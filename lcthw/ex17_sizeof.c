#include <stdio.h>

struct A {
    char ch;
    char *strP;
    char str[255];
};

int main(){
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(char *): %lu\n", sizeof(char *));
    printf("sizeof(char[255]): %lu\n", sizeof(char[255]));
    printf("sizeof(char) + sizeof(char *) + sizeof(char[255]): %lu\n", sizeof(char) + sizeof(char *) + sizeof(char[255]));
    printf("sizeof(struct A): %lu\n", sizeof(struct A));
}
