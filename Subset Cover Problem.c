//Q12 Greedy subset

#include <stdio.h>
#include <stdlib.h>

#define MAX_SETS 100
#define MAX_ITEMS 100

int sets[MAX_SETS][MAX_ITEMS];
int num_sets;
int num_items;

int chosen[MAX_SETS];
int num_chosen;

int uncovered[MAX_ITEMS];
int num_uncovered;

void read_input() {
    int i, j;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of subsets: ");
    scanf("%d", &num_sets);
    for (i = 0; i < num_sets; i++) {
        printf("Enter the number of items in subset %d: ", i + 1);
        int size;
        scanf("%d", &size);
        for (j = 0; j < size; j++) {
            scanf("%d", &sets[i][j]);
        }
    }
}

int compare(const void* a, const void* b) {
    int* arr_a = (int*) a;
    int* arr_b = (int*) b;
    return arr_b[1] - arr_a[1];
}

void choose_sets() {
    int i, j;
    while (num_uncovered > 0) {
        int best_set = -1;
        int best_set_count = 0;
        for (i = 0; i < num_sets; i++) {
            if (chosen[i]) continue;
            int count = 0;
            for (j = 0; j < num_items; j++) {
                if (uncovered[j] && sets[i][j]) {
                    count++;
                }
            }
            if (count > best_set_count) {
                best_set = i;
                best_set_count = count;
            }
        }
        if (best_set == -1) {
            printf("Error: No set chosen\n");
            return;
        }
        chosen[best_set] = 1;
        num_chosen++;
        for (j = 0; j < num_items; j++) {
            if (uncovered[j] && sets[best_set][j]) {
                uncovered[j] = 0;
                num_uncovered--;
            }
        }
    }
}

void print_solution() {
    int i;
    printf("The minimum number of subsets required is %d\n", num_chosen);
    printf("The chosen subsets are:\n");
    for (i = 0; i < num_sets; i++) {
        if (chosen[i]) {
            printf("Subset %d\n", i + 1);
        }
    }
}

int main() {
    read_input();
    int i;
    for (i = 0; i < num_items; i++) {
        uncovered[i] = 1;
    }
    num_uncovered = num_items;
    qsort(sets, num_sets, sizeof(int) * MAX_ITEMS, compare);
    choose_sets();
    print_solution();
    return 0;
}
