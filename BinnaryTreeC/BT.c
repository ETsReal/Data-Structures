#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
} Node;

typedef struct BT {
    Node* root;
} BT;

bool empty(BT* bt){
    if(bt -> root == NULL){
        return true;    
    }
    return false;

}

void printBT(BT* bt){
    printf("root: %d \n",bt -> root -> data);
    printf("root left: %d \n",bt -> root -> left -> data);
    printf("root direita: %d \n",bt -> root -> right -> data);
}

Node* add2(int data, Node* node){
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = data;
    if (node == NULL){
        node = newNode;
        return node;
    }
    else if(data < node -> data){
        node -> left = add2(data, node -> left);
    }
    else if(data > node -> data){
        node -> right = add2(data, node -> right);
    }
}

void add(BT* bt, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = data;
    if(bt -> root == NULL){
        bt -> root = newNode;
        bt -> root -> left = NULL;
        bt -> root -> right = NULL;
    }
    else{
        add2(data, bt -> root);
    }
}


int main(){
    BT* bt = malloc(sizeof(BT));
    bt -> root = NULL;
    add(bt, 4);
    add(bt, 5);
    add(bt, 3);
    printBT(bt);
}