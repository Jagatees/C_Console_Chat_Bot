//
//  j_node.h
//  EzDB
//
//  Created by Jagateesvaran on 28/10/23.
//

#ifndef j_node_h
#define j_node_h

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct node {
    char value[256];
    char key[256];
    struct node* next;
};

typedef struct node node_t;

// Create A New Node
node_t *create_new_node(char *key, char *value);

// Find Key Node
int find_node(node_t *head, char *key);

// Show All - (Print)
void printlist(node_t *head);
// Insert
node_t *insert_at_head(node_t **head, node_t *node_to_insert);

// delete node
void delete_node(node_t **head, int index);


// UPDATE
//void update_node(node_t *head, char *key, char *newValue);
int update_node(node_t *head, char *key, char *newvalue);

#endif /* j_node_h */
