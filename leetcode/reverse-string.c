#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize){
    char ch;
    while(sSize > 1){
        ch = s[0];
        s[0] = s[sSize - 1];
        s[sSize - 1] = ch;
        s++;
        sSize -= 2;
    }
}

int main(){
    char s[] = "abcdefg";
    int sSize = strlen(s);
    printf("s: %s \nsSize:%d\nsSize/2: %d\nsSize>>1:%d \n", s, sSize, sSize/2, sSize>>1);
    reverseString(s, strlen(s));
    printf("reversed s: %s\n", s);
}
