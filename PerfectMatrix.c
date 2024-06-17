#include <stdio.h>
#define N 3

int PerfectMatrix(int** mat)
{
    if(mat == NULL)
        return 0;
    
    int maxnum = mat[0][0];
    int count = 0;

    for(int i = 0; i < N - 1; i++)
        {
            for(int j = 0; j < N - 1; j++ )
            {
                for(int k = j + 1; k < N; k++)
                {
                    if(mat[i][j] > mat[i][k])
                    {
                        int temp = mat[i][j];
                        mat[i][j] = mat[i][k];
                        mat[i][k] = temp;
                    }
                }

            }
        }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N -1; j++)
        {
            if(mat[i][j] == mat[i][j+1])
            {
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N -1; j++)
        {
            if(mat[i][j] > maxnum)
            {
                maxnum = mat[i][j];
                count = 1;
            }
            else if(mat[i][j] == maxnum)
            {
                count++;
            }
        }
    }

    if(count < 3)
    {
        return 0;  
    }
    return 1;
}