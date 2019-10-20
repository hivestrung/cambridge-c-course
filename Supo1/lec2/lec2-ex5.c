// macro
#include <stdio.h>

#define SWAP(x, y) \
    {              \
        x = y ^ x; \
        y = y ^ x; \
        x = y ^ x; \
    }

int f(int x)
{
    return x * 2;
    }

    /* Function to print an array */
    void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    int main()
    {
        // fixed size array
        int v[] = {64, 34, 25, 12, 22, 11, 90};
        //int n = sizeof(arr) / sizeof(arr[0]); // number of elements
        int w[] = {1, 2, 3, 4, 5, 6, 7};
        int i = 0;
        int x = 1;
        SWAP(v[i], w[f(x)]); // no i++
        // we WANT to get positions 0 and 2 switched
        printArray(v, sizeof(v)/sizeof(v[0]));
        // 3 34 25 12 22 11 90
        printArray(w, sizeof(w) / sizeof(w[0]));
        // 1 2 64 4 5 6 7
}
