/*
        10  20  40  30
        0   1   2   3
        if n = 2
        new node is created and inserted at n
        new node = 5
        10  20  40  5   30
        0   1   2   3   4
*/

#include "stdio.h"
#include "stdlib.h"

struct nodeType {
    int data;
    struct nodeType* next;
};

typedef struct nodeType Node;

Node* createNode(int value){
    Node* node =  (Node*) malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void insertNodeAtHead(Node** head, Node* insert){
    insert->next = *head;
    *head = insert;
}

void insertNodeAtNth(Node* head, int n, int value){
    Node* next;
    Node* newNode;
    newNode = createNode(value);
    for (int i = 0; i < n; i++)
    {
        head = head -> next;
    }
    next = head -> next;
    head -> next = newNode;
    newNode -> next = next;
}

void printList(Node* head){

    while (head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tmp;
    int n = 0, i = 0, value = 0;
    printf("Enter Capacity Of LinkedList:\n");
    scanf("%d",&n);
    printf("Enter %d values \n", n);
    
    //insert at head
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        tmp = createNode(value);
        insertNodeAtHead(&head, tmp);
    }
    printList(head);

    printf("Enter the Position At which new node to be inserted: \n");
    scanf("%d", &n);
    
    printf("Enter the Value : \n");
    scanf("%d", &value);

    insertNodeAtNth(head,n, value);
    printList(head);

    return 0;
}
