//linkedlists.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t; 


void printlist(node_t *head) {
    if (head == NULL) {
        printf("error");
    } else {
        while (head!=NULL) {
            printf("%d-",head->val);
            head = head->next; //head is copied value, so its fine to change it
        }
        printf("\n");
    }
}

//function allocates memory, dont forget to free it!
node_t* create_new_node(int val) {
    node_t* result= (node_t*) malloc(sizeof(node_t));
    result->val = val;
    result->next = NULL;
    return result;
}
    

int main() {
    node_t n1, n2, n3;
    node_t *head;

    n1.val =45;
    n2.val =8;
    n3.val =32;
    node_t *tmp = create_new_node(48);


    head = &n3;
    n3.next = &n2;
    n2.next = tmp;
    tmp->next=&n1;
    n1.next = NULL;

    printlist(head);

    return 0;
}
