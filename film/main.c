#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE_LENGTH 40

struct film {
    char title[TITLE_LENGTH];
    int rate;
};

struct film_list {
    struct film movie;
    struct film_list * next;
};

int getFilm(struct film);

int main(void){
    puts("This program record film in list");
    struct film_list current;
    do {
        struct film movie;
        getFilm(movie);
        current.movie = movie;
        struct film_list next; 
        current.next = &next;
        current = *current.next;
        printf("film.title: %s, film.rate: %d\n", movie.title, movie.rate);
        puts("continue?(y/n)");
        char ch;
        if((ch = getchar()) == 'n'){
            break;
        }
    } while(1);
    return 0;
}

int getFilm(struct film movie){
    puts("Please input film name:");
    scanf("%s", movie.title);
    puts("Please input rate of the film:");
    scanf("%d", &movie.rate);
    return 1;
}
