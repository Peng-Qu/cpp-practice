This problem involves the use of 2D array and recursion.

Description for the meaning of "Spiral Transposition":
https://edabit.com/challenge/jZkyy7tgMoQFJ3QgL

The below informations are divided into 3 parts:

Part 1: Flow of the program

Part 2: Logic of the recursive function to print out the 2D-array

Part 3: Potential problems in the recursive function

### Part 1 (Flow of the program):
1) takes in 2 integers which represent the number of rows and columns of the 2D-array

2) takes in the entries of the 2D-array "row by row"

3) print out the entries linearly according to spiral transposition, i.e. in one row

### Part 2 (Logic of the recursive function to print out the 2D-array):

Task: We need a recursive function to print out the 2D-array "spiral by spiral" (a spiral is a clockwise circle around the array).
      We would like to print from the outermost spiral and to the innermost spiral. Before we move on to the the logic of the
      recursive function, we need to understand how the printing is being done.
      
#### Steps of the printing:
Step 1) Start at left upper corner [0][0]. Print the entries of the first row from left to right until right upper corner [0][n-1]

Step 2) Start at [1][n-1] (one entry below right upper corner). Print down until to [m-1-1][n-1] which is one entry 
      above right bottom corner
      
Step 3) Print the entries across the bottom row. Start at right bottom corner. Print until [m-1][0] which is the bottom left corner

Step 4) Print from one entry above left bottom corner until [1][0], which is one entry below the starting point.

This prints out the outermost circle. Then we repeat step 1 - 4 to print the next circle inside which is smaller.

Second cycle:
Start at [1][1], first print the upper row, from [1][1] to [1][n-1-1]. Then move downward, from [1][n-1-1] to [m-1-1][n-1-1].
Next, print from bottom right to bottom left [m-1-1][1]. Lastly, print upward to [2][1].
## 
Hence, it is clear that the recursive function should be called from innermost circle to outermost circle so that
the printing will be done backward, printing the outermost circle first and the innermost circle last.

At this moment, the header of the function may look like this:

            void recursion (int array [][], int m, int n, int cycle)
The argument cycle is for determining the size of the circle since everytime we call the next recursion the circle will be
2 units longer on each side.

The last problem that needs to be dealt with is to determine how many repetition we need to print out all the spiral. For 
square matrix, it is very intuitive.

      Size(nxn)      cycles needed
      2x2                 1
      3x3                 2
      4x4                 2
      5x5                 3


However, if it is a rectangular matrix, the rule above will be irrelevant. We need a more general rule to determine the
cycles needed, which is the number of entries in the diagonal (entry 00, 11, 22...)

      The number of cycles needed for both square and rectangle is the quotient of (n+1)/2

Now, we have all the informations needed to construct the recursive function.
    
### Part 3 (Potential problems in the recursive function):

Step 1 to 4 can print one complete square. However, not all 2D-array is a square matrix. If the 2D-array is a rectangle, 
the last spiral will be printed out w/o completing the whole 4-step-cycle. We need an if-statement to check against 
those kind of situations, otherwise, the entries in the last spiral will be printed out TWICE. For example, for a rectangle 
in portrait position (vertical), Step 2 and 4 will repeat the same entries. For landscape position (horizontal), Step 1 and 3 
will repeat the same entries.

To solve this, a general guideline is that we can add an if-statement when printing Step 3 and 4, where the conditional statement will
be "if for this recursive step, the top left corner and top right corner is the same, it implies this spiral is a vertical straight 
line and so we dont need Step 3". Similar for step 4.
       
End
