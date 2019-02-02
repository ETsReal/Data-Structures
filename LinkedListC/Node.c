#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Node
{
   int data;
   struct Node *next;
} Node;

void add(Node* head,int data){
    Node* new_node = malloc(sizeof(Node));
    new_node -> data = data;
    Node* current = head;
    while (current -> next != NULL){
        current = current -> next;
    }
    current -> next = new_node;
}

void printLL(Node* head){
    while(head -> next != NULL){
        printf("%d \n", head -> next -> data);
        head = head -> next;
    }
}

int shearch(Node* head, int value){
    Node* current = head;
    while (current != NULL){
        if (current -> data == value){
            printf("Value found! \n");
            return current -> data;
        }
        current = current -> next;
    }
    printf("Value not found \n");
    return -1;
}

bool removeNode(Node* head, int value){
    Node* current = head;
    while (current -> next != NULL){
        if (current -> next -> data == value){
            current -> next = current -> next -> next;
            return true;
        }
        current = current -> next;
    }
    return false;
}


int main(){
    Node* head = malloc(sizeof(Node));
    add(head, 1);
    add(head, 2);  
    add(head, 3);
    add(head, 4);
    add(head, 5);
    removeNode(head, 1);
    printLL(head);
}

