/**
 * When I read C primer plus the s_gets function was confusing me
 * write is to figure out what find \n and the getchar is used for 
 */

#include <stdio.h>
#include <string.h>

char * s_gets(char * str, int n);

int main(){
    int length = 5;
    char str[length];
    puts("Input string to test s_gets:");
    s_gets(str, length);
    printf("Your input is %s\n", str);
    return 0;
}

char * s_gets(char * str, int n){
    char * ret;
    char * find;
    ret = fgets(str, n, stdin); //get string from stdin, stop when n-1 char received or meet \n or EOF 
    if(ret){
        find = strchr(str, '\n');
        if(find){ // this means input lenth is less than n 
            *find = '\0';
        } else {
            while(getchar() != '\n'){ //when input length is larger than n, discard the rest of them, so the input will not be defective to next input line
                continue;
            }
        }
    }
    return ret;
}
