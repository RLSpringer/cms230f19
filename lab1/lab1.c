#include <stdio.h>

// function returns an int derived by adding all numbers between 0 and
// the int argument supplied.  Returns 0 if arg is <= 0.
int sum_to(int n) {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += i;
    }
    return sum;
}


int main(void) {
  printf("%d\n", sum_to(9));
  return 0;
}
