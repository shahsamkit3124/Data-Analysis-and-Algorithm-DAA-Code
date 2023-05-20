//Q22 Backtracking Knapsack

#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int w[MAX_ITEMS], p[MAX_ITEMS]; // weights and profits of items
int n, max_weight; // number of items and maximum weight of knapsack
int max_profit; // maximum profit found so far
int cur_weight, cur_profit; // current weight and profit while searching

void knapsack(int i) {
    if (i == n) {
        // reached the end of the item list
        if (cur_profit > max_profit) {
            max_profit = cur_profit; // update maximum profit
        }
        return;
    }

    // choose to include current item
    if (cur_weight + w[i] <= max_weight) {
        cur_weight += w[i];
        cur_profit += p[i];
        knapsack(i + 1);
        cur_weight -= w[i];
        cur_profit -= p[i];
    }

    // choose to exclude current item
    knapsack(i + 1);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &max_weight);

    max_profit = 0;
    cur_weight = 0;
    cur_profit = 0;

    knapsack(0);

    printf("Maximum profit: %d\n", max_profit);

    return 0;
}
