#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int num, step, isSelfDividing, digit, remainder;
    int *res = malloc(sizeof(int) * (right - left));
    *returnSize = 0;
    for(num = left; num <= right; num++){
        isSelfDividing = 1;
        remainder = 0;
        for(step = 10; remainder != num; step *= 10){
            remainder = num % step;
            digit = remainder / (step / 10);
            if(digit == 0 || num % digit != 0){
                isSelfDividing = 0;
                break;
            }
        }
        if(isSelfDividing == 1){
            res[(*returnSize)++] = num;
        }
    }
    res = realloc(res, sizeof(int) * *returnSize);
    return res;
}

int main(){
    int left = 1, right = 10000;
    int returnSize[1], *selfDividingNums;
    selfDividingNums = selfDividingNumbers(left, right, returnSize);
    printf("left: %d, right: %d\n", left, right);
    printf("self dividing numbers: ");
    for(int i = 0; i < *returnSize; i++){
        printf("%d ", selfDividingNums[i]);
    }
    printf("\n");
}

