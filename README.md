# CS2-A1
A1 Report - Trey Phillips, 2018

For this assignment, I approached the solution through bottom-up design.
First, I went through the specifications and wrote out the pre and post conditions 
of each function, including the required parameters. Then I designed an algorithm
for each function and implemeted it in a function definition. 

For the program, I assumed a 1 dimensional array. The first function modified the
size of the array by reference via reading from A1.dat, writing the data to a
dynamically allocated array whose address was returned. The second and fourth functions
took pointer and size arguments and used basic algorithms for output. The third
merely read the array data by address and wrote nonzeros to the next zero space in the
array. The counting of nonzero values was counted using the access table array.

Once I had the code sound in theory, I developed a driver to test it.
For the driver, I opened A1.dat and continuously read the file until all data
had been processed through the various functions. No arrays were declared in the main;
only pointers were passed as arguments to all functions.

Once I got the code to compile and run correctly, I reviewed the assignment prompt
to make sure that I met all requirements.

