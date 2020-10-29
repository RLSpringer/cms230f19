#include <stdio.h>

void fun(int b) {
    int a = 5;
    
    int c;

    c = a / b;
    printf("Result is %d\n", c);
}

int main(void) {
    int x;
    char c[30];

    printf("Enter a number: ");
    scanf("%d", &x);

    fun(x);
    return 0;
}

