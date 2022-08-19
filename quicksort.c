#include <stdio.h>
#include <stdlib.h> //for atoi and srand

//next function swaps integers without temp
void swap (int arr[], int i, int j) {
        if (i!=j) {
    arr[i]+=arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]-=arr[j];
    }    
} 

int partition (int arr[], int wall_l, int wall_r) {
    //int pivot = srand(wall_l)%(wall_r-wall_l);
    //swap(arr, pivot, wall_r);
    int pivotpos = wall_l;
    for (int j=wall_l; j<wall_r; j++) {
        if (arr[j]<arr[wall_r]) {
            pivotpos++;
            swap(arr, pivotpos-1, j);
        }
    }
    swap(arr, wall_r,pivotpos);
    return pivotpos;
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
//testing partition
    printf("pivot is %d\n",partition(target, 0, argc-1));

    for (int i=0; i<argc-1; i++) {
        printf ("%d ", target[i]);
    }
    return 0;
}
