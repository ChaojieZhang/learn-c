#include <stdio.h>

char* toLowerCase(char* str) {
    int i = 0;
    while(str[i] != '\0'){
        if(65 <= str[i] && str[i] <= 90){
            str[i] += 32;
        }
        i++;
    }
    return str;
}

int main(){
    char str[] = "ABCDEFGHIJKLMNOPQRSTOVWXYZasdfasdfal;af;lskndf;as12390><:{{{[[[sdf?/]]]}}}";
    printf("str      : %s\n", str);
    toLowerCase(str);
    printf("lower str: %s\n", str);
}
