// macro
#include <stdio.h>

#define SWAP(t, x, y) \
    {                \
        t SWAP = x;   \
        x = y;        \
        y = SWAP;     \
    }                 \


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
        SWAP(int, v[i++], w[f(x)]);
        // we WANT to get positions 0 and 2 switched
        printArray(v, sizeof(v)/sizeof(v[0]));
        // 64 3 25 12 22 11 90
        // we expected: 3 34 25 12 22 11 90
        printArray(w, sizeof(w) / sizeof(w[0]));
        // 1 2 64 4 5 6 7
        // we expected: 1 2 64 4 5 6 7
        /* What happens (I think?):
        / i is 0, f(x) is 2
        / 64 is saved into temp variable
        / i is 1, f(x) is still 2
        / v[1] = w[2]
        / w[2] = temp (which is 64)
        */
}
