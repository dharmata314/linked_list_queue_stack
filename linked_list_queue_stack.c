#include "linked_list_queue_stack.h"

List* create_list()
{
    List *list = malloc(sizeof(List));

    if (list == NULL) 
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

bool is_empty(List* list)
{
    return (list->size == 0);
}

int size(List* list)
{

    if (list == NULL) 
    {
        fprintf(stderr, "Error: NULL list\n");
        return -1;
    }

    return list->size;
}

int peek(List* list)
{
    if (is_empty(list)) printf("List is empty\n");

    else
    {
    int value = list->head->value;
    return value;
    }
}

void append(List *list, int value)
{
    if (list == NULL) 
    {
        fprintf(stderr, "Error: NULL list\n");
        exit(EXIT_FAILURE);
    }

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = NULL;

    if (is_empty(list))
    {
        list->head = new_node;
        list->tail = new_node;
    }

    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void prepend(List *list, int value)
{
    if (list == NULL) 
    {
        fprintf(stderr, "Error: NULL list\n");
        exit(EXIT_FAILURE);
    }

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = NULL;

    if (is_empty(list))
    {
        list->head = new_node;
        list->head->next = NULL;
    }

    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }

    list->size++;
}

void print_list(List *list)
{
    if (list == NULL) 
    {
        fprintf(stderr, "Error: NULL list\n");
        exit(EXIT_FAILURE);
    }

    if (is_empty(list)) 
    {
        fprintf(stderr, "Error: Attempting to print an empty list\n");
        return;
    }

    Node* current_node = list->head;

    while (current_node != NULL)
    {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
}

void destroy_list(List *list)
{
    if (list == NULL) 
    {
        fprintf(stderr, "Error: Attempting to destroy a NULL list\n");
        exit(EXIT_FAILURE);
    }
    
    if (is_empty(list)) 
    {
        fprintf(stderr, "Error: Attempting to destroy an empty list\n");
        return;
    }

    Node *currentNode = list->head;

    while(currentNode != NULL)
    {
        Node * tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }

    free(list);
}

int dequeue(List *list)
{
    if (is_empty(list)) 
    {
    fprintf(stderr, "Error: Attempting to dequeue a NULL list\n");
    exit(EXIT_FAILURE);
    }

    else
    {
        int value = list->head->value;

        Node *old_head = list->head;

        if (list->size == 1)
        {
            list->head = NULL;
            list->tail = NULL;
        }

        else 
        {
            list->head = list->head->next;
        }

        free(old_head);

        list->size--;

        return value;
    }
}

void insert(List *list, int position, int value)
{
    if (is_empty(list))
    {
    fprintf(stderr, "Error: Attempting to insert in an empty list\n");
    return;
    }

    if (position == 1) 
    {
        prepend(list, value);
        return;
    }

    if (position > list->size)
    {
        printf("Position is greater than the size of the list. You can use append function to add an element to the end of the list\n");
        return;
    }

    if (position < 1) printf("Posiion is lesser that the size of the list\n");

    Node * new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->value = value;
    new_node->next = NULL;

    Node *current_node = list->head;
    
    for (int i = 1; i < position - 1 && current_node != NULL; i++)
    {
        current_node = current_node->next;
    }
    
    new_node->next = current_node->next;
    current_node->next = new_node;

    if (new_node->next == NULL) list->tail = new_node;

    list->size++;
}

void delete(List* list, int position)
{
    if (is_empty(list))
    {
        printf("Attemptind to delete an element in an empty list\n");
        return;
    }

    if (position == 1) 
    {
        dequeue(list);
        return;
    }

    if (position > list->size || position < 1)
    {
        printf("Position is not in the list\n");
        return;
    }

    Node * current_node = list->head;

    for (int i = 1; i < position - 1; i++)
    {
        current_node = current_node->next;
    }

    Node * node_to_delete = current_node->next;

    current_node->next = node_to_delete->next;

    node_to_delete->next = NULL;

    free(node_to_delete);
}

int search(List *list, int key)
{
    if (is_empty(list))
    {
    fprintf(stderr, "Error: Attempting to search in an empty list\n");
    return -1;
    }

    else 
    {
        Node *current_node = list->head;
        int position = 1;
        while (current_node != NULL)
        {
            if (current_node->value == key) return position;
            current_node = current_node->next;
            position++;
        }

        return 0;
    }
}

