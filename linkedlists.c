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
    if (result!=NULL) {
        result->val = val;
        result->next = NULL;
    }
    return result;
}
    
//funcion deletes whole list from head by freeing memory
void delete_whole (node_t *head) {
    if (head == NULL) {
        printf("error");
    } else {
        do {
            node_t *temporary = head;
            head = head->next;
            free(temporary);
        } while (head!=NULL); 
    }
}


int main() {
    node_t *head = create_new_node (45);
    node_t *tmp1 = create_new_node(21);
    node_t *tmp2 = create_new_node(68);
    node_t *tmp3 = create_new_node(55);



    head->next = tmp3;
    tmp3->next = tmp2;
    tmp2->next = tmp1;
    tmp1->next = NULL;

    printlist (head);

    delete_whole (head);

    printlist (head);
    return 0;
}
