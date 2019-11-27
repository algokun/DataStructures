/*
    Depth First Search Algorithm
*/

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

Node* insertNode(Node* root, int data){
    if(root == NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insertNode(root->left , data);
    else
        root->right = insertNode(root->right , data);
    return root;
}

// Left Root Right
void printInorder(Node* root) 
{ 
    if (root == NULL) 
        return ;

    printInorder(root->left); 
    printf("%d \t", root->data); 
    printInorder(root->right); 
} 

// Root Left Right
void printPreOrder(Node* root){
    if(root == NULL)
        return;
    
    printf("%d \t", root->data); 
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//Left Right Root
void printPostOrder(Node* root){
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d \t", root->data);     
}

void levelOrderTraversal(){
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 5 , 15 , 2 , 8 , 6 , 25};
    int i = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = NULL;
    root = createNode(arr[0]);
    for (int i = 1; i < size ; i++)
    {
        insertNode(root , arr[i]);
    }
    printf("Inorder Traversal:\n");
    printInorder(root);
    printf("\nPreorder Traversal:\n");
    printPreOrder(root);
    printf("\nPostorder Traversal:\n");
    printPostOrder(root);
    return 0;
}
