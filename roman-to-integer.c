/**
 * https://leetcode.com/problems/roman-to-integer/
 */

#include <stdio.h>

int romanToInt(char * s){
    int num = 0;
    char ch;
    char pre = '\0'; //must assign a initial value, or the rand pre could be one of roman num character
    while((ch = *s++) != '\0'){
        switch(ch){
            case 'I':
                num += 1;
                break;
            case 'V':
                if(pre == 'I'){
                    num -= 2;
                }
                num += 5;
                break;
            case 'X':
                if(pre == 'I'){
                    num -= 2;
                }
                num += 10;
                break;
            case 'L':
                if(pre == 'X'){
                    num -= 20;
                }
                num += 50;
                break;
            case 'C':
                if(pre == 'X'){
                    num -= 20;
                }
                num += 100;
                break;
            case 'D':
                if(pre == 'C'){
                    num -= 200;
                }
                num += 500;
                break;
            case 'M':
                if(pre == 'C'){
                    num -= 200;
                }
                num += 1000;
                break;
        }
        pre = ch;
    }
    return num;
}

int main(){
    char romanNum[6][100] = {
      "III",
      "IV",
      "IX",
      "LVIII",
      "MCMXCIV",
      "CMLXXXIV"
    };

    for(int i = 0; i < 6; i++){
        printf("%s - %d\n", romanNum[i], romanToInt(romanNum[i]));
    }
}
