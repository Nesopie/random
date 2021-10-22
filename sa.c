#include<stdio.h>
#include<stdlib.h>

typedef struct stack stack;

struct stack {
    int top;
    int *stackArray;
    int size;
};

stack push(stack stackArray, int data) {
    if(++stackArray.top == stackArray.size) {
        printf("Stack overflow, increasing the size\n");
        //if top + 1 = size then increase the sie by two
        stackArray.stackArray = (int*)realloc(stackArray.stackArray, stackArray.size * 2);
        stackArray.size *= 2;
        stackArray.stackArray[stackArray.top] = data;
    }else {
        stackArray.stackArray[stackArray.top] = data;
    }
    return stackArray;
}

void display(stack stackArray) {
    if(stackArray.top == -1) {
        printf("Stack underflow");
        return;
    }

    for(int i = stackArray.top; i >= 0; i--) {
        printf("%d\n", stackArray.stackArray[i]);
    }
}

void pop(stack stackArray) {
    if(stackArray.top == -1) {
        printf("Stack is empty");
    }else {
        stackArray.top--;
    }
}

void peek(stack stackArray) {
    printf("%d",stackArray.top);
}

int main(int argc, char **argv) {
    stack stackArray;

    //initialising the stack 
    stackArray.top = -1;
    stackArray.stackArray = (int*)calloc(10, sizeof(int));
    stackArray.size = 10;

    stackArray = push(stackArray, 1);
    stackArray = push(stackArray, 2);
    stackArray = push(stackArray, 3);
    stackArray = push(stackArray, 4);
    stackArray = push(stackArray, 5);
    stackArray = push(stackArray, 6);
    stackArray = push(stackArray, 7);
    stackArray = push(stackArray, 8);
    stackArray = push(stackArray, 9);
    stackArray = push(stackArray, 10);
    stackArray = push(stackArray, 11);
    stackArray = push(stackArray, 12);

    display(stackArray);

    return 0;
}
