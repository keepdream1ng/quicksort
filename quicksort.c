//quicksort.c
//#include "quicksort.h" 
#include <stdio.h>

//функция печати для отладки
void printarr(int arr[], int i,int j) {
    for (;i<=j; i++) {printf("%d ", arr[i]);}
    printf("\n");
}
    

//next function swaps integers without temp
void swap (int arr[], int i, int j) {
        if (i!=j) {
    arr[i]+=arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]-=arr[j];
    }    
} 

int partition (int arr[], int wall_l, int wall_r) {
    int pivotpos = wall_l;
    for (int j=wall_l; j<wall_r; j++) {
        if (arr[j]<=arr[wall_r]) {
            swap(arr, pivotpos++, j);
        }
    }
    if (arr[pivotpos]>arr[wall_r]) {
        swap(arr, wall_r,pivotpos); //условие выше, на случай готового куска
    }
    return pivotpos; // все значение до этой позиции меньше
}

void quicksort (int arr[], int wall_l, int wall_r) {
    if (wall_l<wall_r) {
        int pivot = partition(arr, wall_l, wall_r);
        quicksort(arr, wall_l, pivot-1);
        quicksort(arr, pivot, wall_r);
    }
}

/* для оформления отдельного main работающего с pipeline
int main (int argc, char **argv) {
    if (argc<=2) return 0; // защита памяти, нечего сортировать

//making array with ints, not strings
    int target[argc-1];
    for (int i=1; i<argc; i++) {
       target[i-1]=atoi(argv[i]); 
    }

    quicksort(target, 0, argc-2);

    printarr(target,0, argc-2);
    
    return 0;
}
*/
