#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/// W/B - Unoccupied white/black squares
/// F - Bishop figure
/// O - Occupied

void fillBoard(char board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 1)
        {
            for (int ii = 0; ii < 8; ii++)
            {
                if (ii % 2 == 1)
                {
                    board[i][ii] = 'W';
                }
                else
                {
                    board[i][ii] = 'B';
                }
            }
        }
        else
        {
            for (int ii = 0; ii < 8; ii++)
            {
                if (ii % 2 == 1)
                {
                    board[i][ii] = 'B';
                }
                else
                {
                    board[i][ii] = 'W';
                }
            }
        }
    }
}

void printBoard(char board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int ii = 0; ii < 8; ii++)
        {
            printf(" %c ", board[i][ii]);
        }
        printf("\n");
    }
    printf("\n");
}

void insertBishop(char board[8][8], int x, int y, char figure, char toProject)
{
    board[y][x] = figure;
    int tempx = x;
    int tempy = y;
    /// right down
    while (tempx < 7 && tempy < 7)
    {
        tempx++;
        tempy++;

        board[tempy][tempx] = toProject;
    }
    tempx = x;
    tempy = y;
    /// right up
    while (tempx < 7 && tempy > 0)
    {
        tempx++;
        tempy--;
        board[tempy][tempx] = toProject;
    }
    tempx = x;
    tempy = y;
    /// left up
    while (tempx > 0 && tempy > 0)
    {
        tempx--;
        tempy--;
        board[tempy][tempx] = toProject;
    }
    tempx = x;
    tempy = y;
    /// left down
    while (tempx > 0 && tempy < 7)
    {
        tempx--;
        tempy++;
        board[tempy][tempx] = toProject;
    }
}

bool checkIfFull(char board[8][8], char toCheck)
{
    char temp;
    for (int i = 0; i < 8; i++)
    {
        for (int ii = 0; ii < 8; ii++)
        {
            temp = board[i][ii];
            if (temp == toCheck)
            {
                return false;
            }
        }
    }
    printf("\n\n");
    return true;
}

bool place(int i, int start, char board[8][8])
{
    if (i == 8)
    {
        if (checkIfFull(board, 'W'))
        {
            printBoard(board);
            return true;
        }
    }
    else
    {
        for (int j = start; j < 32; j++)
        {
            int row = j / 4;
            int col = 2 * (j % 4) + row % 2;
            insertBishop(board, col, row, 'F', 'O');

            if (place(i + 1, j + 1, board))
            {
                return true;
            }
            insertBishop(board, col, row, 'W', 'W');
        }
    }

    return false;
}
bool placeBlack(int i, int start, char board[8][8])
{
    if (i == 8)
    {
        if (checkIfFull(board, 'B'))
        {
            printBoard(board);
            return true;
        }
    }
    else
    {
        for (int j = start; j < 32; j++)
        {
            int row = j / 4;
            int col = 2 * (j % 4) + row % 2;
            if (row % 2 == 1)
            {
                col -= 1;
            }
            else
            {
                col += 1;
            }

            insertBishop(board, col, row, 'F', 'O');

            if (placeBlack(i + 1, j + 1, board))
            {
                return true;
            }
            insertBishop(board, col, row, 'B', 'B');
        }
    }

    return false;
}

void invertSolution(char board[8][8])
{

    for (int i = 0; i < 8; i++)
    {
        for (int ii = 0; ii < 8; ii++)
        {
            if (board[i][ii] == 'F')
            {
                if (ii == 0)
                {
                    insertBishop(board, ii + 1, i, 'F', 'O');
                }
                else
                {
                    insertBishop(board, ii - 1, i, 'F', 'O');
                }
            }
        }
    }
}

int main()
{
    clock_t start_t, end_t, total_t;
    int i;
    int n = 8;
    char board[n][n];
    fillBoard(board);

    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    printf("Going to start calculating, start_t = %ld\n", start_t);
    place(0, 0, board);

    /// placeBlack(0, 0, board);

    invertSolution(board);
    end_t = clock();
    printf("End of the calculating, end_t = %ld\n", end_t);

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);

    /// printBoard(board);

    return 0;
}