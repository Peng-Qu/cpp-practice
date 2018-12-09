## Introduction

In this assignment, you are going to practise circular linked list, classes, and dynamic memory. 

Please read all the descriptions carefully in the subsequent tabs before you start.


We are dealing with an m-by-n matrix (m rows and n columns).
Please note that we are NOT going to use 2D-array to represent the matrix. The details of how the matrix is stored is introduced in Description. 
The following operations are defined for a matrix. Let A be a 3-by-4 matrix as below for better explanation. Throughout the assignment, we count the rows and columns from the index 0 to align with our programming convention.

![image](https://user-images.githubusercontent.com/42372844/49693892-3f57af00-fbba-11e8-9326-1ac06241f12e.png)

**Right Circular Shift**: A particular row of a matrix performs a circular shift to the right by one cell. If we perform a right circular shift on Row-0 of A, it becomes

![image](https://user-images.githubusercontent.com/42372844/49693896-60b89b00-fbba-11e8-8211-583f4c8d256c.png)

**Left Circular Shift**: Similar to right circular shift except it shifts to the left. If we perform a left circular shift on Row-1 of A, it becomes

![image](https://user-images.githubusercontent.com/42372844/49693908-9cebfb80-fbba-11e8-8a35-6db65ca0627c.png)

**Up Circular Shift**: A particular column of a matrix performs a circular shift upward. If we perform an up circular shift on Col-0 of A, it becomes

![image](https://user-images.githubusercontent.com/42372844/49693932-1c79ca80-fbbb-11e8-8485-c59e9b5456d3.png)

**Down Circular Shift**: Similar to up circular shift except it shifts download. If we perform a down circular shift on Col-3 of A, it becomes

![image](https://user-images.githubusercontent.com/42372844/49693936-3adfc600-fbbb-11e8-8bd1-5266de190526.png)

**Reverse Row**: A particular row of a matrix is flipped. If we perform a reverse row on Row-2 of A, it becomes

![image](https://user-images.githubusercontent.com/42372844/49693939-4f23c300-fbbb-11e8-9b00-e3d2d967369e.png)

We also define that a matrix is **in-order** if the matrix is in the following form:

![image](https://user-images.githubusercontent.com/42372844/49693943-7084af00-fbbb-11e8-9c50-76242d99cd2b.png)

Similarly, a matrix is **in-reverse-order** if the matrix is in the following form:

![image](https://user-images.githubusercontent.com/42372844/49693949-81cdbb80-fbbb-11e8-848a-e7678a456d68.png)

A user may perform the above operations on the matrix and the program stops when the matrix is in-reverse-order. You may think that this program would be much easier to implement using 2D arrays. However, it will be a very very good practice on pointers using linked lists, in particular, "2D" circular linked lists (i.e. circular linked lists of circular linked lists).

# Acknowledgement
HKUST COMP2011 2018 Fall Assignment
