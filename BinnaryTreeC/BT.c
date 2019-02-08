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
    printf("root left: %d \n",bt -> root -> left -> left -> data);
    printf("root left: %d \n",bt -> root -> left -> left -> left -> data);
    
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

Node* remove2(Node* current, int data){
    if(current -> data == data){
        if(current -> left == NULL && current -> right != NULL){
            current = current -> right;
            return current;
        }
        else if(current -> right == NULL && current -> left != NULL){
            current = current -> left;
            return current;
        }
        else if(current -> left == NULL && current -> right == NULL){
            current = NULL;
            return current;
        }
    }
    else if(data < current -> data){
        current -> left = remove2(current -> left, data);
    }
    else if(data > current -> data){
        current -> right = remove2(current -> right, data);
    }
}

Node* removeBT(BT* bt, int data){
    remove2(bt -> root, data);
}

Node* BTmin(Node* current){
    while(current -> left != NULL){
        current = current -> left;
    }
    return current;
}


int main(){
    BT* bt = malloc(sizeof(BT));
    bt -> root = NULL;
    add(bt, 5);
    add(bt, 4);
    add(bt, 3);
    add(bt, 2);
    printBT(bt);
    Node* ola =  BTmin(bt -> root);
    printf("minimo %d \n", ola -> data);
}