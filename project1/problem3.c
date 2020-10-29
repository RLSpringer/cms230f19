#include <stdio.h>
#include <stdlib.h>

// print numbers from user generated number, except
// numbers divisible by 3, 5, 3 and 5
int main() {
    int n = 0;
    printf("How many outputs shall I generate? ");
    scanf("%d", &n);
    printf("\n");
    // if input <= 0, dont print anything
    if (n <= 0) {
        return EXIT_SUCCESS;
    } else {
        for (int i = 1; i <= n; i++) {
            if ((i % 3 == 0) && (i % 5 == 0)) {
                printf("HeyHowdy\n");
            } else if (i % 3 == 0) {
                printf("Hey\n");
            } else if (i % 5 == 0) {
                printf("Howdy\n");
            } else {
                printf("%d\n", i);
            }
        }
    }
    return EXIT_SUCCESS;
}
