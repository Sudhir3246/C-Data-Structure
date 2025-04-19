#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *prev,*next;
};
struct node * create(struct node * start)
{
	struct node *new;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item for 1st Node:\n");
		scanf("%d",&item);
		new->info = item;
		start = new;
		new->prev = start;
		new->next = start;
	}
	return (start);
}
void traverse(struct node *start)
{
	struct node *ptr = start;
	printf("\n CDLL Contains:\n");
	printf("%d\t",ptr->info);
	ptr=ptr->next;
	while(ptr != start)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
struct node * insert_beg(struct node * start)
{
	struct node *new,*ptr;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info = item;
		new->prev = NULL;
		new->next = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr = start -> prev;
			ptr->next = new;
			new->prev = ptr;
			new->next = start;
			start -> prev = new;
			start = new;
		}
		traverse(start);
	}
	return (start);
}
struct node * insert_end(struct node * start)
{
	struct node *new,*ptr;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info = item;
		new->prev = NULL;
		new->next = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr = start -> prev;
			ptr->next = new;
			new->prev = ptr;
			new->next = start;
			start -> prev = new;
		}
		traverse(start);
	}
	return (start);
}
struct node * delete_beg(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start;
		printf("\nItem Deleted:%d\n",ptr->info);
		start= ptr->next;
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr -> next;
		traverse(start);
		free(ptr);
	}
	return(start);
}

struct node * delete_end(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start ->prev;
		printf("\nItem Deleted:%d\n",ptr->info);
		ptr->prev->next = start;
		start->prev = ptr -> prev;
		traverse(start);
		free(ptr);
	}
	return(start);
}
main()
{
	struct node *start = NULL;
	int op;
	start=create(start);
    do
    {
    	printf("\nMenu:\n1.Traverse.\n2.Insert_Beg\n3.Delete_Beg\n4.Insert_End\n5.Delete_End\n6.Exit.\n");
    	printf("\nEnter Your Choice:\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:traverse(start);
			       break;
    		case 2:start=insert_beg(start);
				   break;
    		case 3:start=delete_beg(start);
			       break;
    		case 4:start=insert_end(start);
			       break;
    		case 5:start=delete_end(start);
			       break;
			case 6:exit(0);
		}
	}
while(op<7);
}
      
