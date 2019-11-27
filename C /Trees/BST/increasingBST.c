// Simplified Version of GeeksForGeeks
#include "stdio.h"
#include "stdlib.h"

typedef struct binaryTreeNodeType{
    int data;
    struct binaryTreeNodeType *left, *right;
} Node;

Node* createNode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
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

void printInorder(Node* root) 
{ 
    if (root != NULL) 
    { 
        printInorder(root->left); 
        printf("%d \n", root->data); 
        printInorder(root->right); 
    } 
} 

int main(){
    Node* root = NULL;
    Node* tmp;
    int a[13] = {5,3,6,2,4,-1,8,1,-1,-1,-1,7,9};
    root = insertNode(root , a[0]);
    for (int i = 1; i < 13; i++)
    {
        if(a[i] != -1)
            insertNode(root , a[i]);
    }
    printInorder(root);
    return 0;
}
