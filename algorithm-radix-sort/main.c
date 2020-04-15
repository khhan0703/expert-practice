#include <stdio.h>

void print(int arr[], int n)
{
    for(register int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print4bit(int arr[], int n) 
{
    int bitmask1 = 1;
    int bitmask2 = 2;
    int bitmask4 = 4;
    int bitmask8 = 8;
    printf ("------\n");
    for (register int r = 0; r<n; r++)
    {
        printf("%d%d%d%d", (arr[r]&bitmask8)>>3, (arr[r]&bitmask4)>>2, (arr[r]&bitmask2)>>1, arr[r]&bitmask1);
        printf("\n");
    }
    printf ("------\n");
}

extern int binaryRadixSort(int data[], int n, int digit, int startIdx, int endIdx);

int main()
{
    int arr[10] = {9, 8, 7, 4, 3, 1, 2, 10, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    //print(arr, n);
    binaryRadixSort(arr, n, 4, 0, n-1);
    //print(arr, n);

    
    return 0;
}
