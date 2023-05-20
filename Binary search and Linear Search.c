// Q1 DAC Linear_Binary

#include <stdio.h>
// Function to perform linear search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to perform binary search using divide and conquer approach
int binarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, low, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, key);
        }
    }
    return -1; // Key not found
}

int main()
{
    int n, key, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    printf("Enter your choice:\n");
    printf("1. Linear search\n");
    printf("2. Binary search\n");
    scanf("%d", &choice);
    int index;
    switch (choice)
    {
    case 1:
        index = linearSearch(arr, n, key);
        if (index == -1)
        {
            printf("Key not found\n");
        }
        else
        {
            printf("Key found at index %d\n", index);
        }
        break;
    case 2:
        index = binarySearch(arr, 0, n - 1, key);
        if (index == -1)
        {
            printf("Key not found\n");
        }
        else
        {
            printf("Key found at index %d\n", index);
        }
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}
