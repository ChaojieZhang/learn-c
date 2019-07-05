#include <stdio.h>

int main(){
    int i = 123;
    unsigned int ui = 123;
    float f = 1.23;
    double d = 1.2334;
    char c = 'c';
    char s[] = "string123456";
    
    printf("integer: %d\n", i);
    printf("float: %f\n", f);
    printf("double: %f\n", d);
    printf("double : %.2f\n", d);
    printf("hex: %x\n", ui);
    printf("char: %c\n", c);
    printf("string: %s\n", s);
}
