/* A1.cpp - Trey Phillips */
/* Reads matrices from A1.dat */
/* Displays matrices */
/* Analyzes matrices to find nonzero values and addresses */
/* Returns fixed matrices and access table of row addresses */

#include<iostream>
#include<fstream>

using namespace std;

/*Reads matrix size and data from in_file*/
/*Takes rows and cols parameters for writing, takes in_file for reading matrix*/
/*Modifies rows and cols by reference, returns address of matrix array*/
int* array_addrss(int &rows, int &cols, ifstream &in_file);

/*Displays matrix from array_addrss*/
/*Takes size and address of array for matrix*/
/*Output function: no returns*/
void prnt_array(int *array_addrss, int rows, int cols);

/*Restructures matrix by making nonzeros sequential in array*/
/*Makes access table using pointer*/
/*Takes size, address of matrix array, address of access table*/
/*Modifies table to include number of nonzeros total after each row*/
/*Also modifies array so nonzeros are at beginning of array*/
void recnstrct_mtrx(int *array_pntr, int rows, int cols, int *&tble_pntr);

/*Displays matrix and access table from array and table addresses*/
/*Takes array and table pointers and matrix size*/
/*Output function: no return*/
void prnt_array(int *array_pntr, int rows, int cols, int *tble_pntr);

int main()
{
	ifstream in_file;	// opens A1.dat for processing
	in_file.open("A1.dat");
	if(in_file.fail())
	{
		cout << "Error opening file.\n";
		system("pause");
		exit(1);
	}	  // check for file fail

	int rows, cols;	// matrix dimensions

	while(!in_file.eof())	// reads new matrices until end of file
	{			
		int* mtrx_pntr = array_addrss(rows, cols, in_file);

		int *accss_tble = NULL;	// declaring and initializing access table to zero

		cout << "Original Matrix:\n\n";	// display of original matrix
		prnt_array(mtrx_pntr, rows, cols);

		cout << "\nNew Matrix:\n\n";	// modification and display of new matrix
		recnstrct_mtrx(mtrx_pntr, rows, cols, accss_tble);
		prnt_array(mtrx_pntr, rows, cols, accss_tble);

		accss_tble = NULL;	// nullification and deletion of pointers
		mtrx_pntr = NULL;
		delete [] accss_tble;
		delete [] mtrx_pntr;
	}

	in_file.close();	// file close

	cout << "Goodbye!\n";
	
	system("pause");
	return 0;
}

int* array_addrss(int &rows, int &cols, ifstream& in_file)
{
	in_file >> rows >> cols;	// first two numbers give matrix size

	int* matrix = 0;	// declaring dynamically allocated array to hold matrix
	if (matrix != 0)
		delete[] matrix;
	matrix = new int[rows*cols];	// size = rows * columns

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			in_file >> matrix[(i*cols)+j];	// in_file feeds data into matrix data points

		return matrix;	// returns address of matrix array declared in function scope
}

void prnt_array(int *array_addrss, int rows, int cols)
{
	for(int i=0; i<rows; i++)
	{
		cout << "\t";	// new row
		for(int j=0; j<cols; j++)
			cout << *(array_addrss+((i*cols)+j)) << " ";	// prints matrix data from address
		cout << endl;	// next row
	}
}

void recnstrct_mtrx(int *array_pntr, int rows, int cols, int *&tble_pntr)
{
	int *temp, index = 0;	// temp for current value, index for next nonzero index
	
	tble_pntr = new int[rows + 1];	// size is rows + 1
	for (int i = 0; i < (rows + 1); i++)	// all values initialized to zero
		(*(tble_pntr + i)) = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp = (array_pntr + (i *cols) + j);
			if (*temp)	// if nonzero, becomes next element in array
			{
				*(array_pntr + index) = *(array_pntr + (i*cols) + j);	// assigns current after next nonzero
				index++;
			}
		}
		(*(tble_pntr + i + 1)) = index; // makes table value for current row accumulated nonzeros
	}
}

void prnt_array(int *array_pntr, int rows, int cols, int *tble_pntr)
{
	for (int i = 0; i < (rows + 1); i++)
	{
		cout << *(tble_pntr + i) << "\t";	// current row table value
		for (int j = 0; j < ((*(tble_pntr + i + 1)) - *(tble_pntr + i)); j++)	// loops based on next table value - current
			cout << *(array_pntr + *(tble_pntr + i) + j) << " ";	// prints next value
		cout << endl;	// next row
	}
	cout << endl;
}