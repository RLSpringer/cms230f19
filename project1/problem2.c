#include <stdio.h>
#include <stdlib.h>

int main() {
    int arrowhead = 0;
    int shaft = 0;
    int i = 0;
    int j = 0;
    printf("How many rows high for the arrowhead? ");
    scanf("%d", &arrowhead);
    printf("\nHow many rows high for the shaft? ");
    scanf("%d", &shaft);
    printf("\n");

    // if both arrowhead and shaft are <= 0, dont
    // print anything
    if (arrowhead <= 0 && shaft <= 0) {
        return EXIT_SUCCESS;
    } else {
        // print arrowhead
        for (i = 1; i <= arrowhead; i++) {
            for (j = i; j <= arrowhead; j++) {
                printf(" ");
            }
            for (j = 0; j < i; j++) {
                printf("**");
            }
            printf("\n");
        }
        // print shaft
        for (i = 1; i <= shaft; i++) {
            for (j = 0; j < arrowhead; j++) {
                printf(" ");
            }
            printf("**\n");
        }
    }
    return EXIT_SUCCESS;
}
