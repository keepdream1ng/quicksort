#include <stdio.h>
#include <stdlib.h> //for atoi and srand
#include "quicksort.h"

#define MAX_INPUT 100
#define ARRAY_INCREMENT 100 

int main (int argc, char **argv) {
    if (argc<=2) { //for the pipeline input
        char input[MAX_INPUT];
        int *target_arr = (int *) malloc(ARRAY_INCREMENT * sizeof(int));
        int index = 0;
        int count = 1;
        while (scanf("%s", input)!=EOF) {
            if (input[0]=='q') return 0; // exit from programm screen
            if (index + 1==ARRAY_INCREMENT*count) {
                count++;
                target_arr = (int *) realloc(target_arr, ARRAY_INCREMENT * count * sizeof(int));
            }
            target_arr[index]=atoi(input);
            index++;
        }
        quicksort (target_arr, 0, index-1);
        printarr (target_arr, 0, index-1);
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
