// bubble sort for fixed array
#include <stdio.h>

void swap_lousy(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap_lousy(arr, j, j + 1);
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    // fixed size array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n); // should be [11, 12, 22, 25, 34, 64, 90]
    return 0;
}
