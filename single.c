#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *create(struct node *start) {
    int item;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("\nOVERFLOW");
    else {
        printf("\nEnter Item:\n");
        scanf("%d", &item);
        new->info = item;
        new->link = NULL;
        if (start == NULL)
            start = new;
    }
    return start;
}

void traverse(struct node *start) {
    struct node *Ptr = start;
    printf("\nSLL CONTAINS:\n");
    while (Ptr != NULL) {
        printf("%d\t", Ptr->info);
        Ptr = Ptr->link;
    }
    printf("\n");
}

struct node *insert_beg(struct node *start) {
    int item;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("\nOVERFLOW");
    else {
        printf("\nEnter Item:\n");
        scanf("%d", &item);
        new->info = item;
        new->link = start;
        start = new;
    }
    traverse(start);
    return start;
}

struct node *insert_end(struct node *start) {
    int item;
    struct node *new, *Ptr;
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("\nOVERFLOW");
    else {
        printf("\nEnter Item:\n");
        scanf("%d", &item);
        new->info = item;
        new->link = NULL;
        if (start == NULL) {
            start = new;
        } else {
            Ptr = start;
            while (Ptr->link != NULL) 
                Ptr = Ptr->link;
            
            Ptr->link = new;
        }
    }
    traverse(start);
    return start;
}

int main() {
    struct node *start = NULL;
    int op;
    start = create(start);
    do {
        printf("\nMenu:\n1. Traverse\n2. Insert at Beginning\n3. Insert at End\n4. Exit\nEnter your choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                traverse(start);
                break;
            case 2: 
                start = insert_beg(start);
                break;
            case 3: 
                start = insert_end(start);
                break;
            case 4: 
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (op < 4);
    return 0;
}
