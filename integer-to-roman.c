/**
 * https://leetcode.com/problems/integer-to-roman/
 */

#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num){
    char *s = malloc(100 * sizeof(char));
    int remainder; 
    for(int i = 10; (remainder = num % i) != 0; i *= 10){
        num = num - remainder;
        printf("%d\n", remainder);
    }
    return s;
}

int main(){
    int nums[23] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 17, 19, 49, 58, 99, 234, 432, 600, 789, 1011, 2032, 3413};
    for(int i = 0; i < 23; i++){
        printf("%d - %s\n", nums[i], intToRoman(nums[i]));
    }
}
