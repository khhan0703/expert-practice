#include <stdio.h>

void print(int arr[], int n)
{
    for(register int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);
    printf("Hello world!\n");
    return 0;
}
