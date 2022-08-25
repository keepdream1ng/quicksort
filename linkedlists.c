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
    
//function deletes whole list from head by freeing memory
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

//function connects node to the pointed node and pushes if there is something
node_t* insert_node_after(node_t *target_node, node_t *node_to_insert) {
    if (target_node->next != NULL) {
        node_to_insert->next=target_node->next;
    }
    target_node->next = node_to_insert;
    return node_to_insert; // so this is easy to chain
}
