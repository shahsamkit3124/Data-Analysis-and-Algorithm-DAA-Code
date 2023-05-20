// Q6 Greedy knapsack

#include <stdio.h>
struct knapsack
{
    int itemno;
    float profit;
    float weight;
    float ppw;
    float part;
};
void sort(int n, struct knapsack item[])
{
    int i;
    struct knapsack temp;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (item[j].ppw < item[j + 1].ppw)
            {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n, i;
    float capacity;
    printf("Enter the number of items:");
    scanf("%d", &n);
    struct knapsack item[n];
    for (i = 0; i < n; i++)
    {
        item[i].itemno = i + 1;
        printf("Enter the profit of item %d: ", i + 1);
        scanf("%f", &item[i].profit);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%f", &item[i].weight);
        item[i].ppw = item[i].profit / item[i].weight;
    }
    sort(n, item);
    printf("Enter max Capacity:");
    scanf("%f", &capacity);
    float totalprofit=0;
    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            item[i].part = 0;
        }
        else if (item[i].weight <= capacity)
        {
            item[i].part = 1;
            capacity = capacity - item[i].weight;
            totalprofit += item[i].profit;
        }
        else
        {
            item[i].part = (capacity / item[i].weight);
            capacity = 0;
            totalprofit += (item[i].profit * item[i].part);
        }
    }
    printf("Item no\t Profit \t Weight\t\t Profit/weight\t Paartition\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", item[i].itemno,item[i].profit,item[i].weight,item[i].ppw,item[i].part);

    }
    printf("Total profit earned :- %.2f \n",totalprofit);
}

