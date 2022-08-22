//quicksort.h
#ifndef QSORT_HEADER 
#define QSORT_HEADER

//функция печати для отладки
void printarr(int arr[], int i,int j); 

//next function swaps integers without temp
void swap (int arr[], int i, int j);

//next function rearrenges array and gives position of member whitch is greater when previos
int partition (int arr[], int wall_l, int wall_r);

//reqursion function for partition and separation of array
void quicksort (int arr[], int wall_l, int wall_r);

#endif //for ifndef
