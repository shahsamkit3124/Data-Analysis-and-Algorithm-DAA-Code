
//Q24 BranchBound knapsack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int bound(int w, int v, int i, int *weights, int *values, int n, int lb, int ub)
{
    int j, k;
    for (j = i, k = w; j < n && k < ub; j++)
    {
        k += weights[j];
        v += values[j];
    }
    if (k > ub)
    {
        v -= values[j - 1];
        k -= weights[j - 1];
        v += (ub - k) * (values[j - 1] / weights[j - 1]);
    }
    for (j = i, k = w; j < n && k < lb; j++)
    {
        k += weights[j];
        v += values[j];
    }
    if (k > lb)
    {
        v -= values[j - 1];
        k -= weights[j - 1];
        v += (lb - k) * (values[j - 1] / weights[j - 1]);
    }
    return v;
}

void knapsack_bb(int w, int v, int i, int *weights, int *values, int n, int lb, int ub, int *best_value, int *solution)
{
    if (i == n)
    {
        if (v > *best_value)
        {
            *best_value = v;
            for (int j = 0; j < n; j++)
            {
                solution[j] = (w & (1 << j)) ? 1 : 0;
            }
        }
        return;
    }
    if (bound(w, v, i, weights, values, n, lb, ub) > *best_value)
    {
        knapsack_bb(w, v, i + 1, weights, values, n, lb, ub, best_value, solution);
        w |= 1 << i;
        v += values[i];
        if (w <= ub)
        {
            knapsack_bb(w, v, i + 1, weights, values, n, lb, ub, best_value, solution);
        }
        v -= values[i];
        w &= ~(1 << i);
    }
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int lb = 0;
    int ub = capacity;
    int best_value = 0;
    int solution[n] ;
    for (int i = 0; i < n; i++)
    {
        solution[i]=0;
    }


    knapsack_bb(0, 0, 0, weights, values, n, lb, ub, &best_value, solution);

    printf("Maximum value: %d\n", best_value);
    printf("Solution: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", solution[i]);
    }
    printf("\n");

    free(weights);
    free(values);
    return 0;
}

