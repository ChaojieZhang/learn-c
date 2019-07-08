#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

char *Person_rename(struct Person *who, char *name){
    if(who->name != NULL){
        free(who->name);
    }
    who->name = strdup(name);
    return who->name;
}

struct Person *Person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    
    Person_rename(who, name);
    who->age = age;
    who->height= height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who){
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who){
    printf("Name: %s\n", who->name);
    printf("Age: %d\n", who->age);
    printf("Height: %d\n", who->height);
    printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]){
    struct Person *boya  = Person_create("Boya", 12, 156, 53);
    struct Person *golu = Person_create("Golu", 14, 167, 49);

    printf("Boya is at memory location %p\n", boya);
    Person_print(boya);
    printf("Golu is at memory location %p\n", golu);
    Person_print(golu);
    printf("20 years latter.");
    Person_rename(boya, "Boya w golu");
    boya->age += 20;
    boya->height += 18;
    boya->weight += 23;

    Person_rename(golu, "Golu w aka");
    golu->age += 20;
    golu->height += 0;
    golu->weight += 10;

    Person_print(boya);
    Person_print(golu);

    Person_destroy(boya);
    Person_destroy(golu);
    return 0;
}
