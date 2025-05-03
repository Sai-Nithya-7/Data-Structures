#include <stdio.h>
#include "sort.h" 

int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int n, int key);

int main() {
    int size, choice, key, result;
    printf("Enter n of elements to be added: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    // Sort the array first using Bubble Sort from the header file
    BubbleSort(arr, size);
    printf("Sorted Array: ");
    display(arr, size);

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter number from 1-3: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, size, key);
                if (result != -1) 
                {
                    printf("Key found at index %d\n", result);
                } 
                else 
                {
                    printf("Key not found.\n");
                }
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, size, key);
                if (result != -1) 
                {
                    printf("Key found at index %d\n", result);
                } 
                else 
                {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Linear Search
int linearSearch(int arr[], int size, int key) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == key) 
        {
            return i; 
        }
    }
    return -1;  
}

// Binary Search
int binarySearch(int arr[], int size, int key) 
{
    int start = 0; 
    int end = size - 1;
    while(start<=end) 
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key) 
        {
            return mid; // Key found
        } 
        else if (arr[mid] < key) 
        {
            start = mid + 1;
        } 
        else 
        {
            end = mid - 1;
        }
    }
    return -1; // Key not found
}
