
//Q18 Dynamic LCS

#include <stdio.h>
#include <string.h>
void main()
{
    char str1[20], str2[20], arrow[20][20],x[20];
    int m, n, i, j, LCS_table[20][20], k;
    printf("Enter string 1 : ");
    gets(str1);
    printf("Enter string 2 : ");
    gets(str2);
    m = strlen(str1);
    n = strlen(str2);

    // FOR LCS TABLE
    LCS_table[0][0] = 0;
    LCS_table[1][0] = -2;
    LCS_table[0][1] = -2;

    for (i = 2; i <= m + 1; i++)
    {
        LCS_table[i][0] = -1;
    }

    for (i = 2; i <= n + 1; i++)
    {
        LCS_table[0][i] = -1;
    }

    for (i = 1; i <= m + 1; i++)
    {
        LCS_table[i][1] = 0;
    }

    for (i = 1; i <= n + 1; i++)
    {
        LCS_table[1][i] = 0;
    }

    // FOR ARROW MATRIX
    arrow[0][0] = '0';
    arrow[1][0] = 'x';
    arrow[0][1] = 'y';

    for (i = 2,k = 0; i <= m + 1; i++,k++)
    {
        arrow[i][0] = str1[k];
    }

    for (i = 2,k = 0; i <= n + 1; i++,k++)
    {
        arrow[0][i] = str2[k];
    }

    for (i = 1; i <= m + 1; i++)
    {
        arrow[i][1] = '0';
    }

    for (i = 1; i <= n + 1; i++)
    {
        arrow[1][i] = '0';
    }

    for (i = 2; i <= m + 1; i++)
    {
        for (j = 2; j <= n + 1; j++)
        {
            if (str1[i - 2] == str2[j - 2])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                arrow[i][j] = (char)'d';
            }
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j];
                arrow[i][j] = (char)'u';
            }
            else
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
                arrow[i][j] = (char)'l';
            }
        }
    }

    printf("Printing adjacency matrix\n");
    for (i = 0; i <= m + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            printf("%d\t", LCS_table[i][j]);
        }
        printf("\n");
    }

    printf("Printing arrow matrix\n");
    for (i = 0; i <= m + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            printf("%c\t", arrow[i][j]);
        }
        printf("\n");
    }

    i=m+1,j=n+1,k=0;

    while(arrow[i][j]=='l' || arrow[i][j]=='d' || arrow[i][j]=='u')
    {

        if(arrow[i][j]=='u')
        {
            arrow[i][j]=arrow[i-1][j];
            i--;
        }
        else if(arrow[i][j]=='l')
        {
            arrow[i][j]=arrow[i][j-1];
            j--;
        }
        else if(arrow[i][j]=='d')
        {
            // printf("%c ",arrow[i][0]);
            x[k]=arrow[i][0];
            arrow[i][j]=arrow[i-1][j-1];
            i--;
            j--;
            k++;
        }
    }
    printf("Longest common subsequence is \n");
    for (int i = k-1; i>=0; i--)
    {
        printf("%c ", x[i]);
    }
}

