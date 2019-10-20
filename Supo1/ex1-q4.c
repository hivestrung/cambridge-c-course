// bubble sort for fixed array
#include <stdio.h>

void swap(char *val1, char *val2)
{
    char tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void bubbleSort(char arr[], int n)
{
    int i, j;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Function to print an array */
void printArray(char arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    // fixed size array
    char arr[] = {'b', 'c', 'a', 'e', 'A', 'D','d'};
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n); // should be [11, 12, 22, 25, 34, 64, 90]
    return 0;
}
