//linkedlists.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void printlist(node_t* head) {
    if (head == NULL) {
        printf("error");
        return 1;
    }
    do {
        printf("%d-", head->val);
    } while (head->next!=NULL);
}

int main() {

    return 0;
}
