#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE_LENGTH 40

struct film {
    char title[TITLE_LENGTH];
    int rate;
};

struct film_list {
    struct film * movie;
    struct film_list * next;
};

int getFilm(struct film *);
void printList(struct film_list *);

int main(void){
    puts("This program record film in list");
    struct film_list * current;
    struct film_list head;
    current = & head;
    do {
        struct film movie;
        struct film_list next; 
        getFilm(&movie);
        current->movie = &movie;
        puts("Enter done to stop or any other key to continue");
        char directive[5];
        fgets(directive, 5, stdin);
        if(strcmp(directive, "done") == 0){
            current->next = NULL;
            printList(&head);
            break;
        } else {
            current->next = &next;
        }
    } while(1);
    return 0;
}

int getFilm(struct film * movie){
    puts("Please input film name:");
    fgets(movie->title, TITLE_LENGTH, stdin);
    puts("Please input rate of the film:");
    scanf("%d", &movie->rate);
    getchar();
    return 1;
}

void printList(struct film_list * fl){
    printf("tile \t rate");
    while(fl->next != NULL){
        printf("%s \t %d", fl->movie->title, fl->movie->rate);
    }
    printf("\n");
}
