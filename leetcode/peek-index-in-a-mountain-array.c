#include <stdio.h>

int peakIndexInMountainArray(int* A, int ASize){
    int i = 0;
    while(A[i] < A[i+1]){
        i++;
    }
    return i;
}

int main(){
    int ASize = 10;
    int A[10] = { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    int index;
    index = peakIndexInMountainArray(A, ASize);
    printf("index is %d", index);
}
