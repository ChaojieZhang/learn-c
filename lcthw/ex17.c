#include <stdio.h>
#include <assert.h>
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

struct Address{
    int id;
    int set;
    char *name;
    char *email;
};

struct Database{
    struct Address *rows;
    int MAX_ROWS;
    int MAX_DATA;
};

struct Connection{
    FILE *file;
    struct Database *db;
};

void Address_print(struct Address *addr){
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn){
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1){
        die("Failed to load database.");
    }
}

struct Connection *Database_open(const char *filename, char mode){
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn){
        die("Memory erro");
    }

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db){
        die("Memory erro");
    }

    if(mode == 'c'){
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        if(conn->file){
            Database_load(conn);
        }
    }
    if(!conn->file){
        die("Failed to open the file");
    }

    return conn;
}

void Database_close(struct Connection *conn){
    if(conn){
        if(conn->file){
            fclose(conn->file);
        }
        if(conn->db){
            free(conn->db);
        }
        free(conn);
    }
}

void Database_write(struct Connection *conn){
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1){
        die("Failed to write database.");
    }
    
    rc = fflush(conn->file);
    printf("fflush res:  %d\n", rc);
    if(rc == -1){
        die("Can not flush Database.");
    }
}

void Database_create(struct Connection *conn, int max_data, int max_rows){
    conn->db->MAX_DATA = max_data;
    conn->db->MAX_ROWS = max_rows;

    conn->db->rows = malloc(conn->db->MAX_ROWS * sizeof(struct Address));
    int i = 0;


    for(i = 0; i < conn->db->MAX_ROWS; i++){
        struct Address addr = {
            .id = i,
            .set = 0,
            .name = malloc(conn->db->MAX_DATA * sizeof(char)),
            .email = malloc(conn->db->MAX_DATA * sizeof(char))
        };
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email){
    struct Address *addr = &conn->db->rows[id];
    if(addr->set){
        die("Already set, delete it first");
    }

    addr->set = 1;
    char *res = strncpy(addr->name, name, conn->db->MAX_DATA);
    if(!res){
        die("Name copy failed");
    }
    res = strncpy(addr->email, email, conn->db->MAX_DATA);
    if(!res){
        die("Emial copy failed");
    }
}

void Database_get(struct Connection *conn, int id){
    struct Address *addr = &conn->db->rows[id];
    if(addr->set){
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id){
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn){
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < conn->db->MAX_ROWS; i++){
        struct Address *cur = &db->rows[i];
        if(cur->set){
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc < 3){
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }

    int max_data = 512;
    int max_rows = 512;

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;
    
    if(argc > 3){
        id = atoi(argv[3]);
        if(id > conn->db->MAX_ROWS){
            die("There is not that many records.");
        }
    }
    

    switch(action){
        case 'c':
            Database_create(conn, max_data, max_rows);
            Database_write(conn);
            break;
        case 'g':
            if(argc != 4){
                die("Need an id to get.");
            }
            Database_get(conn, id);
            break;
        case 's':
            if(argc !=6){
                die("Need id, name, email, to set");
            }
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;
        case 'd':
            if(argc != 4){
                die("Need an id to delete.");
            }
            Database_delete(conn, id);
            Database_write(conn);
            break;
        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action , onely: c=create, g=get, s=set, d=delete, l=list support");
    }

    Database_close(conn);
    return 0;
}

