#include <stdio.h>
int numJewelsInStones(char* J, char* S) {
    int count = 0;
    char *SHead = S;
    while(*J){
        S =SHead;
        while(*S){
            if(*J == *S){
                count++;
            }
            S++;
        }
        J++;
    }
    return count;
}

int main(){
    char *J = "ab";
    char *S = "asdfaskjasdfbasdfeasdfoc";
    char jewelCount = 0;
    jewelCount = numJewelsInStones(J, S);
    printf("Jewel count is: %d\n", jewelCount);
}
