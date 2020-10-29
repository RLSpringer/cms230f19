#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int value;
    struct node_t* next;
} node;


void printlist(node* head) {
    node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    node* n1 = malloc(sizeof(node));
    node* n2 = malloc(sizeof(node));
    node* n3 = malloc(sizeof(node));
    node* n4 = malloc(sizeof(node));
    node* n5 = malloc(sizeof(node));
    
    n2->value = 2;
    n4->value = 4;
    n4->next = n5;
    n1->value = 1;
    n5->value = 5;
    n5->next = NULL;
    n1->next = n2;
    n3->next = n4;
    n3->value = 3;
    n2->next = n3;
    printlist(n1);
    
    node *n = n1;
    while(n != NULL) {
      node *d = n->next;
      free(n);
      n = d;
    }

}
