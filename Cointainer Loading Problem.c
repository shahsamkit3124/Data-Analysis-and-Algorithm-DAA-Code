// Q13 Greedy Container_Loading

#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTAINERS 100

int compare(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a); // Sort in non-increasing order
}

int container_loading_cover(int containers[], int n, int capacity)
{
    qsort(containers, n, sizeof(int), compare);
    int loaded_weight = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (containers[i] + loaded_weight <= capacity) {
            loaded_weight += containers[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int n, capacity, containers[MAX_CONTAINERS];

    printf("Enter the number of containers: ");
    scanf("%d", &n);

    printf("Enter the capacity of the ship: ");
    scanf("%d", &capacity);

    printf("Enter the weights of the containers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &containers[i]);
    }

    int num_loaded_containers = container_loading_cover(containers, n, capacity);

    printf("The minimum number of containers needed to cover the ship is: %d", num_loaded_containers);

    return 0;
}

