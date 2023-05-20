
//Q23 BranchBound Job

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 20

int n;
int p[MAX_N];
int d[MAX_N];
int w[MAX_N];
int s[MAX_N];
int f[MAX_N];
int upperbound = INT_MAX;
int best_time;
int best_included[MAX_N];

int calcost(int job, int included[MAX_N])
{
    included[job] = 1;
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (included[i] == 0)
        {
            cost += w[i];
        }
    }
    return cost;
}

int calupperbound(int included[MAX_N])
{

    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (included[i] == 0)
        {
            cost += w[i];
        }
    }

    return cost;
}

void solve(int job, int depth, int included[MAX_N], int cost)
{
    for (int i = job + 1; i < n; i++)
    {
        if (included[i] == 0)
        {
            if (job == 0)
            {
                s[i] = 0;
            }
            else
            {
                s[i] = f[job - 1];
            }

            f[i] = s[i] + p[i];
            if (f[i] <= d[i])
            {
                int cost1 = calcost(i, included);
                if (cost1 < upperbound)
                {
                    included[i] = 1;
                    upperbound = calupperbound(included);
                    best_time = upperbound;
                    for (int i = 0; i < n; i++)
                    {
                        best_included[i] = included[i];
                    }
                    solve(i, depth + 1, included, cost1);
                    included[i] = 0;
                }
            }
            included[i] = 0;
        }
    }
}

int main()
{
    printf("Enter the number of jobs (max %d): ", MAX_N);
    scanf("%d", &n);

    printf("Enter the processing times for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the deadlines for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    printf("Enter the Penalties for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    best_time = INT_MAX;
    int included[MAX_N] = {0};
    solve(0, 0, included, 0);

    printf("Minimum cost: %d\n", best_time);
    printf("Jobs included: ");
    for (int i = 0; i < n; i++)
    {
        if (best_included[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    printf("Path taken: ");
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (best_included[i] == 1)
        {
            printf("%d ", i + 1);
            current_time += p[i];
        }
    }
    printf("\n");

    return 0;
}

