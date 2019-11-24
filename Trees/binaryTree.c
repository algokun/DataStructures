#include "stdlib.h"
#include "stdio.h"

typedef struct nodeType{
    int data;
    struct nodeType *left , *right;
} Node;

Node* createNode(int chandu){
    Node* node = malloc(sizeof(Node));
    node->data = chandu;
    node->left = node->right = NULL;
    return node;
}

int main(int argc, char const *argv[])
{
    Node* root = createNode(10);
    root->left = createNode(50);
    root->right = createNode(30);
    return 0;
}
