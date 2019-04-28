#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *res = malloc(ASize * sizeof(int));
    int nextEvenIndex = 0;
    int nextOddIndex = ASize - 1;
    for(int i = 0; i < ASize; i++){
        if(A[i]%2 == 0){
            res[nextEvenIndex] = A[i];
            nextEvenIndex++;
        } else {
            res[nextOddIndex] = A[i];
            nextOddIndex--;
        }
    }
    return res;
}

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int ASize = 10;
    int *A = malloc(ASize * sizeof(int)); 
    int *res;
    for(int i = 0; i < ASize; i++){
        A[i] = rand();
    }
    printf("A:");
    printArr(A, ASize);
    printf("\n");
    res = sortArrayByParity(A, ASize, A);
    printf("res:");
    printArr(res, ASize);
    printf("\n");
}

