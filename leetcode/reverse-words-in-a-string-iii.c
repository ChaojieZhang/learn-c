/**
 * problem: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseWords(char * s){
    int wordStart = 0;
    int wordEnd;
    char swap;
    int i = 0;
    while(1){
        if(s[i] == ' ' || s[i] == '\0'){
           for(wordEnd = i - 1; wordStart < wordEnd; wordStart++, wordEnd--){
               swap = s[wordStart];
               s[wordStart] = s[wordEnd];
               s[wordEnd] = swap;
           }
           wordStart = i + 1; 
        }
        if(s[i] == '\0'){
            break;
        }
        i++;
    }
    return s;
}

int main(){
    char s[] = "this is a test line";
    printf("orgin string: %s\n", s);
    printf("reversed string: %s\n", reverseWords(s));
}
