#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// program to generate fibonacci sequence
int main() {
    int n = 0;
    int num = 0;
    printf("How many terms should I generate boss? ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        num = (1 / sqrt(5)) * (pow(((1+(sqrt(5))) / 2), i)
        -(pow(((1-(sqrt(5))) / 2), i)));
        printf("%d\n", num);
    }
    return EXIT_SUCCESS;
}

