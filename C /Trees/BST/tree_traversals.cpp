/*
    Depth First Search Algorithm
*/

#include <iostream> 
#include <queue> 
using namespace std; 

struct Node{
    int data;
    struct Node *left , *right;
};

Node* createNode(int data){
    Node* node = new Node;
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
    
    cout<<root->data<<"\t";     
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//Left Right Root
void printPostOrder(Node* root){
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<"\t";     
}

void levelOrderTraversal(Node* root){
    if (root == NULL)  return; 

    queue<Node *> q; 

    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front(); 
        cout << node->data << "\t"; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    }
    

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
    printf("\nLeveorder Traversal\n");
    levelOrderTraversal(root);
    return 0;
}
