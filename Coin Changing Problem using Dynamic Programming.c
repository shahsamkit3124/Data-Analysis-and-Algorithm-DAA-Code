
//Q15 Dynamic coin_change

#include <stdio.h>
void main()
{
    int i, n, j, den[100], cost, cg[100][100],min,balance;
    printf("Enter the number of denominations\n");
    scanf("%d", &n);
    printf("Enter denominations\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &den[i]);
    }
    printf("Enter the cost  required\n");
    scanf("%d", &cost);
    cg[0][0] = -2;
    for (i = 0; i < n; i++)
    {
        cg[i + 1][0] = den[i];
    }
    for (i = 0; i <= cost; i++)
    {
        cg[0][i + 1] = i;
        cg[1][i + 1] = cg[0][i + 1];
    }

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=cost+1;j++)
        {
            if((j-1)<den[i-1])
            {
                cg[i][j]=cg[i-1][j];
            }
            else{
                min=(cg[i-1][j]>(cg[i][j-den[i-1]]+1))?(cg[i][j-den[i-1]]+1):cg[i-1][j];
                cg[i][j]=min;
            }
        }
    }
    printf("Coin change matrix\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cost + 1; j++)
        {
            // cg[1][0]=1;
            printf("%d\t", cg[i][j]);
        }
        printf("\n");
    }
    printf("Demoniations used\n");
    i=n;
    j=cost+1;
    balance=cost;
    int dused[10];
    int k=0;
    while(balance!=0)
    {
        if(cg[i][j]==cg[i-1][j])
        {
            i--;
        }
        else{
            dused[k]=den[i-1];
            balance=balance-den[i-1];
            k++;
            i=n;
            j=balance+1;
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%d\t",dused[i]);
    }

}

