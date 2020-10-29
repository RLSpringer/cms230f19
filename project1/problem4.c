#include <stdio.h>
#include <stdlib.h>

// recursive function to calc num of blocks
// in triangle given num of blocks on bottom
// row
int calculate(int x) {
    if (x <= 0) {
        return 0;
    }
    return calculate(x-1) + x;
}

int main() {
    int n = 0;
    printf("How many blocks on the bottom row boss? ");
    scanf("%d", &n);
    printf("\n");

    printf("You need %i blocks total.\n", calculate(n));

    return EXIT_SUCCESS;
}
