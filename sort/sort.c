#include <stdio.h>

int* bubble_sort(int arr[], int len)
{

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}


int main(void)
{
    int arr[] = {3, 1, 22, 12, 2};
    int len = sizeof arr / sizeof(int);

    int* p = bubble_sort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}
