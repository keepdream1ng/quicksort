//linkedlists.c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
}; 
typedef struct node node_t;

void printlist(node_t *head) {
    if (head == NULL) {
        printf("error");
    } else {
        while (head!=NULL) {
            printf("%d-",head->val);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    node_t n1, n2, n3;
    node_t *head;

    n1.val =45;
    n2.val =8;
    n3.val =32;

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    printlist(head);

    return 0;
}
