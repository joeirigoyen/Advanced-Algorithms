# Strassen's Matrix Multiplication Algorithm (C++)
The algorithm itself takes four parameters: ***a***, which is a square vector to be multiplied by the second parameter ***b***, which has to be of the same size as ***a***, therefore both need to be square; the third parameter is a matrix ***s*** of the same size as ***a*** and ***b***, which will contain the solution to the multiplication. Lastly, parameter ***n*** takes the size of the *current* matrix being evaluated. 

It is important to mention that this implementation works recursively as it uses the **divide and conquer** paradigm in order to return the product of both matrices. 


## Files

**reader.cpp** takes a *.txt* file with values written as *comma-separated values* (1,2,3,4...) with each row representing also a row in the matrix to be created. It also contains functions such as:

 - ***printMatrix():*** represents a matrix visually by printing it out on a console.
 - ***printVector():*** represents a particular row from a matrix.
 - ***count():*** returns the number of rows in a *.txt* file.
 - ***initMatrixFromFile():*** returns a matrix after reading a *.txt* file as specified above.

**main.cpp** takes two matrices (*given as arguments on the console*) and performs the Strassen Algorithm to return the product of both matrices. It also prints the algorithm's total runtime.

## How to run:

As this is a project I've worked on Windows only, the console command I used was:

- Compilation:`g++ main.cpp -o main`

- Execution:`./main <file_path_of_txt_1> <file_path_of_txt_2>`

## Sources

I would like to stand out the following implementations from their respective creators, which are the ones I used to get an idea on how to implement the algorithm myself:

 - From **Saahil Mahato**: https://medium.com/swlh/strassens-matrix-multiplication-algorithm-936f42c2b344
 - From **Geeks for Geeks**: https://www.geeksforgeeks.org/strassens-matrix-multiplication-algorithm-implementation/
 - From **Rangel Milushev**: https://github.com/rangelak/Strassen-Matrix-Multiplication 
