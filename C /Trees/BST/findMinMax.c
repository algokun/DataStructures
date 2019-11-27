#include "stdio.h"
#include "stdlib.h"

typedef struct nodeType{
    int data;
    struct nodeType *left , *right;
} Node;

Node* createNode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int getMin(Node* root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int getMax(Node* root){
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

Node* insertNode(Node* root, int data){
    if(root == NULL)
        return createNode(data);
    
    if(data < root->data){
        root->left = insertNode(root->left , data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node* root = NULL;
    int a[] = {5,3,6,2,4,8,1,7,9};
    int size = sizeof(a)/sizeof(a[0]);
    root = insertNode(root , a[0]);
    for (int i = 1; i < size; i++)
    {
        insertNode(root , a[i]);
    }
    printf("Max Element : %d \nMin Element : %d",getMax(root) , getMin(root));
    return 0;
}
