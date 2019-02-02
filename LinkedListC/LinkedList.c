#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node* head;
} LL;

void add(LL* lista, int data){
    Node* new_node = malloc(sizeof(Node));
    new_node -> data = data;
    if (lista -> head == NULL){
        lista -> head = new_node;
    }
    else{
        Node* current = lista -> head;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = new_node;
    }
}
 
void printLL(LL* lista){
    while(lista -> head != NULL){
        printf("%d \n", lista -> head -> data);
        lista -> head = lista -> head -> next;
    }
}

int shearch(LL* lista, int value){
    Node* current = lista -> head;
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

bool removeNode(LL* lista, int value){
    Node* current = lista -> head;
    if (lista -> head -> data == value){
        lista -> head = lista -> head -> next;
        return true;
    }
    else{
        while (current -> next != NULL){
            if (current -> next -> data == value){
                current -> next = current -> next -> next;
                return true;
            }
            current = current -> next;
        }
    }
    return false;
}


int main(){
    LL* linked = malloc(sizeof(LL));
    linked -> head = NULL;
    add(linked, 3);
    add(linked, 5);
    add(linked, 7);
    removeNode(linked, 3);
    printLL(linked);
}
