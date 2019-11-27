/*
        HEAD        INSERT
        H           20
        20 H        40
        40 20 H     30
        30 40 20 H  -
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
    
    //insert at head
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        tmp = createNode(value);
        insertNodeAtHead(&head, tmp);
    }
    printList(head);
    return 0;
}
