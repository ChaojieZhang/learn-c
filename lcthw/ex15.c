#include <stdio.h>

int main(){
    int ages [] = {12, 34, 56, 78, 90};
    char *names[] = {"abc", "def", "hij", "klmn", "opqrst"};

    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    for(i = 0; i < count; i++){
        printf("%s has %d years of alive\n", names[i], ages[i]);
    }

    printf("-----\n");

    int *cur_age = ages;
    char **cur_name = names;
    
    for(i = 0; i < count; i++){
        printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
    }

    printf("-----\n");

    for(i = 0; i < count; i++){
        printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
    }

    printf("-----\n");

    for(cur_age = ages, cur_name = names; (cur_age - ages) < count; cur_age++, cur_name++){
        printf("%s is %d years old.\n", *cur_name, *cur_age);
    }

}
