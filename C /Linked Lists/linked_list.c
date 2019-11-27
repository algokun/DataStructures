#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node *next;
} Node;

Node* createNode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}