/*Q)Write a C program to create a queue using an array and perform the following operation:-
1)Insertion
2)Delection
3)Display*/
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full %d\n", value);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("You Can Insert Only 1 NO:%d\n", value);
    }
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1; 
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1) Insertion \n2) Deletion \n3) Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice!.\n");
        }
    }
}

