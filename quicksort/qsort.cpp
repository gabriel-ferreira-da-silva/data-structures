#include <iostream>
using namespace std;
int tam=24;


int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    
    if (start >= end)
        return;
 
    
    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
/*
void part(int *lista, int start , int end, int *pivot){

}*/

int prior(int *a, int *b ){
    if(a[1]==b[0]) return 1;
    return 0;
}

void swap(int *lista, int a, int b){
    int temp = lista[a];
    lista[a] = lista[b];
    lista[b] = temp;
}


int part(int A[], int l, int r, int pivot) {
    do {
        while(A[++l] < pivot);
        while( (l < r) && A[--r] > pivot);
        swap(A, l, r);
    } while (l < r);
    return l;
}

void qsort(int A[], int i, int j) { // Quicksort
    if (j <= i) return;
    int pivotindex = ((i+j)/2);
    swap(A, pivotindex, j);
    int k = part(A, i-1, j, A[j]);
    swap(A, k, j);
    qsort(A, i, k-1);
    qsort(A, k+1, j);
}

int main(){

    int lista[] = {4,7,3,6,13,1,2,3,4,555,65,6,7,34,1,4,3123,23,333333,100,44,4,5,15};
    
    printf("unsorted:     ");
    for(int i=0 ; i < tam ; i++){
        printf(" %d ", lista[i]);
    }

    
    qsort(lista, 0,tam-1);
    printf("\n");
    printf("qsort:        ");
    for(int i=0 ; i < tam ; i++){
        printf(" %d ", lista[i]);
    }

    printf("\n");
    printf("quicksort:    ");
    quickSort(lista, 0,tam-1);
    for(int i=0 ; i < tam ; i++){
        printf(" %d ", lista[i]);
    }
    
    printf("\n");
    return 0;
}