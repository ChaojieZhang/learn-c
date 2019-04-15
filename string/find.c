#include <stdio.h>

/**
 * find the first word position occurred str
 * return -1 when not foud
 */
int find(char *word, char *str);

int main(int argc, char *argv[]){
    char *str = argv[2];
    char *word = argv[1];
    printf("Word position in string is %d\n", find(word, str));
    return 0;
}

int find(char *word, char *str){
   int i = 0;
   int j;
   while(1){
       if(str[i] == '\0'){
           break;
       }
       j = 0;
       if(str[i] == word[j]){
           while(1){
               j++;
               if(word[j] == '\0'){
                   return i;
               }
               if(str[i + j] != word[j]){
                   break;
               }
           }
           i += j;
       } else {
           i++;
       }
   }
   return -1;
}
