//linkedlists.h
#ifndef SIMPLE_LINKED_HEADER
#define SIMPLE_LINLED_HEADER

typedef struct node {
    int val;
    struct node* next;
} node_t; 

//function prints whole list from head
void printlist(node_t *head);

//function allocates memory, dont forget to free it!
node_t* create_new_node(int val);
    
//function deletes whole list from head by freeing memory
void delete_whole (node_t *head);

//function connects node to the pointed node and pushes if there is something
node_t* insert_node_after(node_t *target_node, node_t *node_to_insert);

#endif //for ifndef

