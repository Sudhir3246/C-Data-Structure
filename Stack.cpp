/*Q)Write a C program to create a Stack using an array and perform the following operation:-
1)Insertion
2)Delection
3)Display*/
#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;
void push(int value) {
    if (top == MAX-1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed: %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)  
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1) Insertion\n2) Deletion\n3) Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

