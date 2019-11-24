/*
    HEAD        INSERT
    H           20
    H 20        40
    H 20 40     30
    H 20 40 30  -
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

void insertNodeAfterHead(Node** head, int value){
    Node* newNode = createNode(value);
    Node* lastNode = *head;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }

    while (lastNode->next != NULL)
        lastNode = lastNode -> next;
    
    lastNode->next = newNode;
    return ;
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
    printf("Enter Capacity Of LinkedList:");
    scanf("%d",&n);
    printf("Enter %d values", n);
    
    //insert after head
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertNodeAfterHead(&head, value);
    }
    printList(head);
    return 0;
}
