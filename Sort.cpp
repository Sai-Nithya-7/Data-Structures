// Menu-driven program for sorting an array using Bubble, Insertion, and Selection sort
#include <stdio.h>
#include <cstdlib>

void display(int arr[], int n);
void BubbleSort(int arr[], int n);
void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);

int main() {
    int size, choice;
    printf("Enter n of elements to be added: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    display(arr, size);
    printf("\n");

    do {
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n");
        printf("Enter a number from 1-4: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                BubbleSort(arr, size);
                printf("Array after sorting: ");
                display(arr, size);
                printf("\n");
                break;

            case 2:
                SelectionSort(arr, size);
                printf("Array after sorting: ");
                display(arr, size);
                printf("\n");
                break;

            case 3:
                InsertionSort(arr, size);
                printf("Array after sorting: ");
                display(arr, size);
                printf("\n");
                break;

            case 4:
                printf("Exiting menu..\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

// Display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}