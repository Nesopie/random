#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node {
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void push_front(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    if(!head) {
        head = tail = newNode;
    }else {
        head = newNode;
        tail->next = head;
    }
}

void push_back(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;

    if(!head) {
        head = tail = newNode;
    }else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pop_front() {
    if(!head) {
        printf("The list is empty\n");
    }else{
        node *prevHead = head;
        head = head->next;

        if(head == prevHead) {
            head = tail = NULL;
        }else {
            tail->next = head;
            free(prevHead);
        }
    }
}

void pop_back() {
    if(!head) {
        printf("The list is empty\n");
    }else {
        node *nodeBeforeTail = head;
        while(nodeBeforeTail->next != tail) {
            nodeBeforeTail = nodeBeforeTail->next;
        }

        if(nodeBeforeTail->next == head) {
            head = tail = NULL;
        }else {
            free(tail);
            tail = nodeBeforeTail;
            tail->next = head;
        }

    }
}

void display() {
    if(!head) {
        printf("The list is empty\n");
    }else {
        node *iterator = head;
        do {
            printf("%d->", iterator->data);
            iterator = iterator->next;
        }while(iterator != head);
        printf("%d\n", tail->next->data);
    }
}

int main() {
    push_back(4);
    push_back(3);
    push_back(2);
    push_back(1);

    display();
    pop_back();
    display();
    pop_back();
    display();
    pop_back();
    display();
    pop_back();
    display();

}