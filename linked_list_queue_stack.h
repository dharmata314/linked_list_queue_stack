#ifndef LINKED_LIST_QUEUE_STACK_H
#define LINKED_LIST_QUEUE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

List* create_list();
bool is_empty(List* list);
int size(List* list);
int peek(List* list);
void append(List *list, int value);
void prepend(List *list, int value);
void print_list(List *list);
void destroy_list(List *list);
int dequeue(List *list);
int search(List *list, int key);
void insert(List *list, int position, int value);
void delete(List* list, int position);

#endif