#include <stdio.h>
char* removeOuterParentheses(char* S) {
    char *SHead = S;
    int parentheseLeftCount = 0;
    int moveLeft = 0;
    char ch;
    while(1){
        ch = *S;
        if(moveLeft > 0){
            *(S-moveLeft) = ch;
        }
        if(ch == '('){
            parentheseLeftCount++;
            if(parentheseLeftCount == 1){
                moveLeft++;
            }
        } else if (ch == ')'){
            if(parentheseLeftCount == 1){
                moveLeft++;  
            } 
            parentheseLeftCount--;
        }
        if(ch == '\0'){
            break;
        }
        S++;
    }
    return SHead;
}

int main(){
    char S[] = "(()())(())";
    printf("S  :%s\n", S);
    char *res = removeOuterParentheses(S);
    printf("res:%s\n", res);
}
