#include <stdio.h>
#include <stdlib.h> //for atoi and srand
#include "quicksort.h"

int main (int argc, char **argv) {
    if (argc<=2) {
        return 0;
        //тут сделать linked lists из STDin которые, потом можно преобразовать в int массив
    }
//making array with ints, not strings
    int target[argc-1];
    for (int i=1; i<argc; i++) {
       target[i-1]=atoi(argv[i]); 
    }

    quicksort(target, 0, argc-2);

    printarr(target,0, argc-2);
    
    return 0;
}
