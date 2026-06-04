#include <stdio.h>
#include <stdlib.h>

int board[20];

int place(int row, int column)
{
    int j;

    for (j = 1; j <= row - 1; j++)
    {
        if ((board[j] == column) ||
            (abs(board[j] - column) == abs(j - row)))
        {
            return 0;
        }
    }

    return 1;
}

void print(int n)
{
    int i, j;

    printf("\nSolution:\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void queens(int row, int n)
{
    int j;

    for (j = 1; j <= n; j++)
    {
        if (place(row, j))
        {
            board[row] = j;

            if (row == n)
                print(n);
            else
                queens(row + 1, n);
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    queens(1, n);

    return 0;
}
