//Q14 Greedy Coin_change

#include <stdio.h>
#include <conio.h>
void main()
{
    int amnt, n, i, j, temp;
    printf("Enter the amount required\n");
    scanf("%d", &amnt);
    printf("Enter the number of denominations\n");
    scanf("%d", &n);
    int den[n],count[n];
    for(i=0;i<n;i++)
    {
        count[i]=0;
    }
    printf("Enter the denominations\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &den[i]);
    }
    // sorting
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (den[j] < den[j + 1])
            {
                temp = den[j];
                den[j] = den[j + 1];
                den[j + 1] = temp;
            }
        }
    }
    while(amnt!=0)
    {
        for(i=0;i<n;i++)
        {
            if(amnt>=den[i])
            {
                count[i]++;
                amnt=amnt-den[i];
                break;
            }
        }
    }
    printf("Denomination\tCoin used\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n",den[i],count[i]);
    }
}

