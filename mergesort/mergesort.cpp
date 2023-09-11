#include<iostream>

void mergesort( int* a, int* temp,int left, int right ){
    if(left == right) return;
    int mid = (left+right)/2;
    mergesort(a, temp, left, mid);
    mergesort(a,temp,mid+1,right);
    for(int i=left; i <=right ;i++){
        temp[i]= a[i];
    }
    int i1 = left ; int i2 = mid + 1;
    for(int curr=left ; curr <=right; curr++){
        if(i1 == mid+1){
            a[curr] =temp[i2++];
        }
        else if(i2> right){
            a[curr] = temp[i1++];
        }else if(temp[i1] < temp[i2]){
            a[curr] =temp[i1++];
        }else{
            a[curr] = temp[i2++];
        }
    }
}

void msort(int* a ){
    int tam = sizeof(a) / sizeof(a[0]);
    //int *temp = new int[tam];

   printf("\nsizeof(a): %d \n",tam);
    for(int i=0; i<tam ; i++){
        printf("a = %d | ",a[i]);
    }
    

    //mergesort(a, temp, 0, tam);
    //delete temp;
}

int main(){
    int a[] = {11,22,11,33,5,7,77,3,44,55,13,4,4,1,5, 2, 1, 6,3};
    int temp[sizeof(a) / sizeof(a[0])];

    printf("before...\n ");
    for(int i=0; i< sizeof(a) / sizeof(a[0]) ; i++)
        printf("%d ",a[i]);
    printf("\n");

    mergesort(a, temp, 0, sizeof(a) / sizeof(a[0]) );
    
    printf("after...\n ");
    for(int i=0; i< sizeof(a) / sizeof(a[0]) ; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}