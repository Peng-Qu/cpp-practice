## Data structure

A matrix is composed of m x n numbers of Element struct. Each Element struct in the matrix is linked to its four neighbors (by the four pointers, namely, up, down, left, right). The Element struct in the boundary is linked with the Element struct at the other end (e.g., the Element struct in Row-0 will have an "up" pointer pointing to an Element struct on Row-(m-1)). 

You are also given a class definition, Matrix, to model the matrix. The Matrix class object contains two private data members, namely, colHeads and rowHeads. Each of them is an array of Element pointers. 

The pointer colHeads[i] is used to refer to Col-i of the matrix and it always points to the Element on Row-0 of Col-i (i.e. 1st element of Col-i). 
The pointer rowHeads[j] is used to refer to Row-j of the matrix and it always points to the Element on Col-0 of Row-j (i.e. 1st element of Row-j). 

The following diagram gives you an idea of how the matrix is represented.

![image](https://user-images.githubusercontent.com/42372844/49693972-fc96d680-fbbb-11e8-8062-32f470d19b35.png)

![image](https://user-images.githubusercontent.com/42372844/49693976-0587a800-fbbc-11e8-8658-e5b45a9d5afb.png)

Note that colHeads[0] and rowHeads[0] shall always point to the same Element struct. After performing a matrix operation, you are required to update the pointers colHeads[i] and rowHeads[j] to maintain the structure of the matrix.

You are forbiddened to use the following in your program:
Any global variable.
The keyword auto and goto.
Any static variable (i.e. using "static" keyword).
Any extra libraries.

# Acknowledgement
HKUST COMP2011 2018 Fall Assignment
