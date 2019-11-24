#include "stdio.h"
#include "stdlib.h"

struct node_t
{
    int data;
    struct node_t *next;
};

typedef struct node_t node;

node* createNode(int data){
    node* result = malloc(sizeof(node*));
    result->data = data;
    result->next = NULL;
    return result;
}

void insertAtHead(node** head, node* insert){
    insert->next = *head;
    *head = insert;
}

int isValueFound(node* head, int value){
    node *temp = head;
    int tempValue, isFound = 0;

    while (temp != NULL)
    {
        tempValue = temp -> data;
        if (tempValue == value)
        {
            isFound++;
        }
        temp = temp -> next;
    }
    return isFound;
}

void printList(node *head){
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d - ", temp -> data);
        temp = temp -> next;
    }
    printf("END\n");
}

int main(int argc, char const *argv[])
{
    int n, tempValue = 0, searchValue;
    node *head = NULL;
    node *tmp;
    // getting length of list
    printf("Enter the length of elements");
    scanf("%d",&n);
    
    // getting n nodes
    printf("Enter %d elements", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&tempValue);
        tmp = createNode(tempValue);
        insertAtHead(&head, tmp);
    }

    printList(head);

    //asking for search value
    printf("Search Value : \n");
    scanf("%d",&searchValue);
    
    printf(isValueFound(head, searchValue) == 1 ? "Element Found" : "Element Found");
    return 0;
}
