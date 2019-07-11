#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *filename = "ex17_fwrite_fread_test_file";
FILE *file;


struct Record {
    long unsigned contentSize;
    char *content;
};

void clean(){
    if(file != NULL){
        fclose(file);
    }
}

void die(char *message){
    clean();
    puts(message);
    exit(1);
}

void write(char *content){
    int contentSize = strlen(content) + 1;
    struct Record record = {
        .contentSize = contentSize
    };

    fwrite(&record, sizeof(struct Record), 1, file);
    fwrite(content, contentSize, 1, file);

    fflush(file);
    printf("Write size: %lu\n", sizeof(struct Record) + contentSize);
}

void read(int count){
    struct Record *record = malloc(sizeof(struct Record));
    while(fread(record, sizeof(struct Record), 1, file)){
        record->content = malloc(sizeof(char) * record->contentSize);
        fread(record->content, record->contentSize, 1, file);
        printf("record.contentSize: %lu\n", record->contentSize);
        printf("record.content: %s\n", record->content);
        printf("\n");
    }
}
    

int main(int argc, char *argv[]){
    char action = 'r';
    if(argc > 1){
        action = argv[1][0];
    }

    //open file
    file = fopen(filename, "a+");
    if(file == NULL){
        puts("Open file failed");
        exit(1);
    }

    switch(action){
        case 'r':
            read(1);
            break;
        case 'w':
            if(argc == 1){
                puts("Phease input write content");
                exit(1);
            }
            write(argv[2]);
            break;
    }

    //close file
    fclose(file);
}
