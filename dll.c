#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node {
    int data;
    node *next;
    node *prev;
};

node *head = NULL;

void push_front(int data) {
    if(!head) {
        head = (node*)malloc(sizeof(node));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
    }else {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;

        head = newNode;
    }
}

void push_back(int data) {
    if(!head) {
        head = (node*)malloc(sizeof(node));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
    }else {
        node *tail = head;
        while(tail->next) {
            tail = tail->next;
        }

        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
    }
}

void pop_front() {
    if(!head) {
        printf("The list is empty\n");
    }else {
        node *temp = head;
        head = head->next;
        if(head) head->prev = NULL;
        else head = NULL;
        free(temp);
    }
}

void pop_back() {
    if(!head) {
        printf("The list is empty\n");
    }else {
        node *tail = head;
        while(tail->next) {
            tail = tail->next;
        }

        node *temp = tail;
        tail = tail->prev;
        if(tail) tail->next = NULL;
        else head = NULL;
        free(temp);
    }
}

void display() {
    if(!head) {
        printf("The list is empty\n");
    }else {
        node *iterator = head;
        while(iterator) {
            printf("%d->",iterator->data);
            iterator = iterator->next;
        }printf("NULL\n");
    }
}

int main() {

    return 0;
}