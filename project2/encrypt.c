#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define ROW 5
#define COL 5

// program to encrypt using Polybius
// Square Cipher provided
int main(void) {
  char buf[MAX];
  char cipher[ROW][COL] = {{ 'l', 'a', 'b', 'o', 'r'},
                           { 'c', 'd', 'e', 'f', 'g'},
                           { 'h', 'i', 'j', 'k', 'm'},
                           { 'n', 'p', 's', 't', 'u'},
                           { 'v', 'w', 'x', 'y', 'z'}};
  fgets(buf, sizeof(buf), stdin);
  for (int i = 0; i < strlen(buf); i++) {
    for (int j = 0; j < ROW; j++) {
      for (int k = 0; k < COL; k++) {
        if (buf[i] == cipher[j][k]) {
          printf("%d%d", j, k);
        }
      }
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}