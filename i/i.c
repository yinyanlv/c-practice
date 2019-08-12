#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i = 0;
    // windows mingw gcc: 1, 2
    // osx gcc: 0, 2
    printf("%d, %d\n", i++, ++i);
    // windows mingw gcc: 4, 4
    // osx gcc: 3, 4
    printf("%d, %d\n", ++i, ++i);
    return 0;
}