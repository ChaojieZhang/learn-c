#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message){
    if(errno){
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef int *(*sort_cb)(int *numbers, int count, compare_cb cmp);

int *select_sort(int *numbers, int count, compare_cb cmp){
    int tempIndex;
    int temp;
    int i;
    int j;

    int *target = malloc(count * sizeof(int));
    if(!target){
        die("Memory error.");
    }
    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++){
        tempIndex = i;
        for(j = i + 1; j < count; j++){
            if(cmp(target[tempIndex], target[j]) > 0){
                tempIndex = j;
            }
        }
        if(tempIndex != i){
           temp = target[i];
           target[i] = target[tempIndex];
           target[tempIndex] = temp;
        }
    }
    return target;
}

int *bubble_sort(int *numbers, int count, compare_cb cmp){
    int temp = 0;
    int i = 0;
    int j = 0;

    int *target = malloc(count * sizeof(int));
    if(!target){
        die("Memory error.");
    }

    memcpy(target, numbers, count * sizeof(int));
    
    for(i = 0; i < count; i++){
        for(j = 0; j < count - 1; j++){
            if(cmp(target[j], target[j+1]) > 0){
               temp = target[j+1];
               target[j+1] = target[j];
               target[j] = temp;
            }
        }
    }
    
    
    // unsigned char *data = (unsigned char *)cmp;
    // for(i = 0; i < 25; i++){
    //     printf("%02x", data[i]);
    // }

    return target;
}

int sorted_order(int a, int b){
    return a - b;
}

int reverse_order(int a, int b){
    return b - a;
}

int strange_order(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    } else {
        return a % b;
    }
}

void test_sorting(int *numbers, int count, sort_cb sort,  compare_cb cmp){
    int i = 0;
    int *sorted = sort(numbers, count, cmp);
    if(!sorted){
        die("Failed to sord as request");
    }

    for(i = 0; i < count; i++){
        printf("%d ", sorted[i]);
    }

    printf("\n");
    free(sorted);
}

char notcmp(){
    return 'a';
}

int main(int argc, char *argv[]){
    if(argc < 2){
        die("Usage: ex18 [number...]");
    }

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;
    
    int *numbers = malloc(count * sizeof(int));
    if(!numbers){
        die("Memory error.");
    }
    
    for(i = 0; i < count; i++){
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, select_sort, sorted_order);
    test_sorting(numbers, count, select_sort, reverse_order);
    test_sorting(numbers, count, select_sort, strange_order);
    test_sorting(numbers, count, bubble_sort, sorted_order);
    test_sorting(numbers, count, bubble_sort, reverse_order);
    test_sorting(numbers, count, bubble_sort, strange_order);
    free(numbers);

    return 0;
}
