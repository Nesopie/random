#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node {
    int data;
    node *next;
};

node* new_node(int data, node *next) {
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = next;
    return p;
}

void insert(node **head, int data, int position) {
    node* temp = new_node(data,NULL);
    if(position == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }

    node* nodeBeforeInsert = *head;
    for(int i = 0; i < position - 2 && nodeBeforeInsert->next; i++) {
        nodeBeforeInsert = nodeBeforeInsert->next;
    }

    temp->next = nodeBeforeInsert->next;
    nodeBeforeInsert->next = temp;
}

void delete(node **head, int position) {
    if(*head) {
        if(position == 1) {
            node *previousHead = *head;
            *head = (*head)->next;
            free(previousHead);
        }else {
            node *nodeBeforeDelete = *head;
            for(int i = 0; i < position - 2 && nodeBeforeDelete->next; i++) {
                nodeBeforeDelete = nodeBeforeDelete->next;
            }

            printf("%d\n",nodeBeforeDelete->data);

            if(!nodeBeforeDelete->next) {
                //if position is beyond the size of the linked list then tail will be nodeBeforeDelete
                // change it to the node before that
                node *temp = *head;
                while(temp->next != nodeBeforeDelete) temp = temp->next;
                nodeBeforeDelete = temp;
            }

            node *nodeToBeDeleted = nodeBeforeDelete->next;
            nodeBeforeDelete->next = nodeBeforeDelete->next->next;
            free(nodeToBeDeleted);
        }
    }else {
        printf("The list is empty\n");
    }
}

int search(node **head, int data) {
    int exists = 0;
    int position = 1;

    for(node *temp = *head; temp ; temp = temp->next) {
        if(temp->data == data) {
            exists = 1;
            break;
        }
        position++;
    }

    return exists ? position : 0;
    // return 0 if it doesn't exist
}

void display(node **head) {
    node *temp = *head;
    while(temp) {
        printf("%d->",temp->data);
        temp = temp->next;
    }printf("NULL\n");
}

int main(int argc, char **argv) {
    node *head = NULL;

    insert(&head,1,1);
    insert(&head,2,2);
    insert(&head,3,1);

    display(&head);

    delete(&head,10);

    display(&head);

    printf("%d",search(&head,2));

    return 0;
}
