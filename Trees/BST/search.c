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

Node* searchNode(Node* root, int key){
    if(root == NULL || root->data == key)
        return root;
    
    if(key < root->data){
        return searchNode(root->left, key);
    }
    
    return searchNode(root->right, key);    
}

void inorder(Node* root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 

int main(){
    Node* root = NULL;
    root = insertNode(root, 100);
    insertNode(root , 20);
    insertNode(root , 500);
    insertNode(root , 10);
    insertNode(root , 30);
    insertNode(root , 40);
    inorder(root);
    return 0;
}
