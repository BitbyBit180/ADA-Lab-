#include <stdio.h>
#include <stdlib.h>   // For abs()

int x[10], n;

/*
    x[row] = column

    Example:
    x[1] = 2
    x[2] = 4
    x[3] = 1
    x[4] = 3

    Means:
    Queen in Row 1 is placed in Column 2
    Queen in Row 2 is placed in Column 4
    Queen in Row 3 is placed in Column 1
    Queen in Row 4 is placed in Column 3
*/


// Function to check whether queen can be placed safely
int place(int k, int i)
{
    int j;

    // Compare with all previously placed queens
    for(j = 1; j < k; j++)
    {
        /*
           x[j] == i
           Checks whether another queen is already
           present in the same column
        */

        /*
           abs(x[j]-i) == abs(j-k)

           Checks whether queens lie on the same
           diagonal

           Example:
           Row 1 Col 1
           Row 2 Col 2

           |1-2| = 1
           |1-2| = 1

           Therefore diagonal attack occurs
        */

        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;   // Not safe
    }

    return 1;           // Safe position
}


// Recursive function to place queens row by row
void nqueen(int k)
{
    int i;

    // Try every column in current row
    for(i = 1; i <= n; i++)
    {
        // Check whether current position is safe
        if(place(k, i))
        {
            // Place queen in row k and column i
            x[k] = i;

            // If all queens are placed
            if(k == n)
            {
                int j;

                printf("\nSolution:\n");

                // Print solution
                for(j = 1; j <= n; j++)
                {
                    printf("Row %d -> Column %d\n",j, x[j]);
                }
            }
            else
            {
                // Place queen in next row
                nqueen(k + 1);
            }
        }
    }
}


int main()
{
    // Read number of queens
    printf("Enter value of N: ");
    scanf("%d", &n);

    // Start placing queen from Row 1
    nqueen(1);

    return 0;
}