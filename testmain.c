#include <stdio.h>
#include <stdlib.h> //for atoi and srand
#include "quicksort.h"
#include "linkedlists.h"

#define MAX_INPUT 100

int main (int argc, char **argv) {
    if (argc<=2) { //for the pipeline input
        char input[MAX_INPUT];
        scanf("%s", input);
        if (input[0]=='q') return 0; // exit from programm screen
        int count = 0;
        node_t *head = create_new_node(atoi(input));
        node_t *tmp = head; // temporary pointer for linked list creation
        while (scanf("%s", input)!=EOF) {
            tmp = insert_node_after( tmp, create_new_node ( atoi(input)));
            count++;
        }
//converting linked list to array for sorting
        int *target_arr = (int *) malloc((count+1) * sizeof(int));
        tmp=head;
        for (int i=0; i<=count; i++) {
            target_arr[i] = tmp->val;
            tmp = tmp->next;
        }
        delete_whole(head);
        quicksort (target_arr, 0, count);
        printarr (target_arr, 0, count);
        free(target_arr);
    } else { // for the terminal input which comes in *argc
//making array with ints, not strings
        int target[argc-1];
        for (int i=1; i<argc; i++) {
            target[i-1]=atoi(argv[i]); 
        }
        quicksort(target, 0, argc-2);
        printarr(target,0, argc-2);
    }    
    return 0;
}
