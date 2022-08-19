#include <stdio.h>
#include <stdlib.h> //for atoi

//next function swaps integers without temp
void swap (int arr[], int i, int j) {
        if (i!=j) {
    arr[i]+=arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]-=arr[j];
    }    
} 

int main (int argc, char **argv) {
    for (int i=0; i<argc; i++) {
        printf("arg %d - %s\n",i, argv[i]);
    }
//making array with ints, not strings
    int target[argc-1];
    for (int i=1; i<argc; i++) {
       target[i-1]=atoi(argv[i]); 
    }
//testing swap
    swap (target,1,3);

    for (int i=0; i<argc-1; i++) {
        printf ("%d ", target[i]);
    }
    return 0;
}
