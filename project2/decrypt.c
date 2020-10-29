#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define ROW 5
#define COL 5

// a program to decrypt using Polybius
// Square Cipher provided
int main(void) {
  char buf[MAX];
  int i = 0;
  int j = 0;
  char cipher[ROW][COL] = {{ 'l', 'a', 'b', 'o', 'r'},
                           { 'c', 'd', 'e', 'f', 'g'},
                           { 'h', 'i', 'j', 'k', 'm'},
                           { 'n', 'p', 's', 't', 'u'},
                           { 'v', 'w', 'x', 'y', 'z'}};
  fgets(buf, sizeof(buf), stdin);
  for (i = 0, j = 1; i < strlen(buf) - 1; i += 2, j += 2) {
    printf("%c", cipher[buf[i] - '0'][buf[j] - '0']);
  }
  printf("\n");
  return EXIT_SUCCESS;
}