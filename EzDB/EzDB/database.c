//
//  database.c
//  EzDB
//
//  Created by Jagateesvaran on 25/10/23.
//

#include "database.h"


// Instruction strut
struct DB {
    const char* SHOW;
    const char* INSERT;
    const char* QUERY;
    const char* UPDATE;
    const char* DELETE;
    const char* ALL;
};

struct DB db_instruction = {
    .SHOW = "SHOW",
    .ALL = "ALL",
    .INSERT = "INSERT",
    .QUERY = "QUERY",
    .UPDATE = "UPDATE",
    .DELETE = "DELETE"
};



// inv is the list of user input string and inc is the counter length
int logic_databse(char *inv[], int inc, node_t **head){
    
    if (inv[0] == NULL) {
        printf("U Enter Nothing So we are kicking u out .\n");
        return 1;
    }
    if (inc >= 2 && strcmp(inv[0], db_instruction.SHOW) == 0 && strcmp(inv[1], db_instruction.ALL) == 0) // SHOW ALL INSTRUCTION
    {
        printf("Welcome to SHOW ALL Instruction\n");
        printlist(*head);
        return 0;
    }
    if (strcmp(inv[0], db_instruction.INSERT) == 0)
    {
        printf("Welcome to INSERT Instruction\n");
        
        // 1 = FOUND
        // 0 = NOT FOUND
        
        int isfound = find_node(*head, inv[1]);
        
        if (isfound == 1) {
            printf("The record with Key=%s already exists in the database\n", inv[1]);
        } else if (isfound == 0){
            // need do some error handling user the 2 value is not a right type
            node_t *tmp = create_new_node(inv[1], inv[2]);
            insert_at_head(head, tmp);
            printf("A new record of Key=%s Value=%s is successfully inserted\n", inv[1], inv[2]);
        }
        
        return 0; // to say if we still in the game
    }
    else if (strcmp(inv[0], db_instruction.QUERY) == 0) // QUERY INSTRUCTION
    {
        printf("Welcome to QUERY Instruction\n");
        
//        To search if there is any existing record with the
//        Key=Mango.
//        If the record exists, EzDB will prompt:
//        • “A record of Key=Mango, Value=6.5 is found
//        in the database.”
//        If there is no record found, EzDB will prompt:
//        • “There is no
        
        query_instruciton();
        
        
        
        
        return 0;
    }
    else if (strcmp(inv[0], db_instruction.UPDATE) == 0) // UPDATE INSTRUCTION
    {
        printf("Welcome to UPDATE Instruction\n");
        return 0;
    }
    else if (strcmp(inv[0], db_instruction.DELETE) == 0) // DELETE INSTRUCTION
    {
        printf("Welcome to DELETE Instruction\n");
        return 0;
    }
    else {
        printf("I don't understand this command %s\n", inv[0]);  // INVAILD INSTRUCTION
        return 0;
    }

    
    
    
    
    return 0;
    
}

void show_all_instruction(void){}
void insert_instruction(void){}
void query_instruciton(void){}
void update_instruciton(void){}
void delete_instruciton(void){}




