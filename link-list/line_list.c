#include <stdio.h>

int main(void) {

    int arr[2] = {11, 22};

    printf("%x\n", &arr[0]);
    printf("%x\n", &arr[1]);

    return 0;
}