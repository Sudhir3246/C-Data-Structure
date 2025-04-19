#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
};
struct node* create_sll(struct node *start)
{
	int item;
	struct node * new;
	new = (struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	printf("\nOVERFLOW\n");
	else
	{
		printf("Enter item:\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		if(start==NULL)
		  start=new;
	}
	return start;	
}
void traverse_sll(struct node * start)
{
	struct node * ptr=start;
	printf("\n SLL contains:\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
}
struct node* insert_beg(struct node *start)
{
	int item;
	struct node * new;
	new = (struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	printf("\nOVERFLOW\n");
	else
	{
		printf("Enter item:\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		if(start==NULL)
		  start=new;
		else
		{
			new->link=start;
			start=new;
		}
	}
	traverse_sll(start);
	return start;
}
struct node* insert_end(struct node *start)
{
	int item;
	struct node * new, *ptr;
	new = (struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	printf("\nOVERFLOW\n");
	else
	{
		printf("Enter item:\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		if(start==NULL)
		  start=new;
		else
		{
			ptr=start;
			while(ptr->link!=NULL)
			ptr=ptr->link;
			
			ptr->link=new;
			
		}
	}
	traverse_sll(start);
	return start;
}
struct node* delete_beg(struct node*start){
	struct node * ptr = start;
	if(start==NULL)
	printf("\nUNDERFLOW\n");
	else{
		start=ptr->link;
		free(ptr);
	}
	traverse_sll(start);return start;
}
struct node* delete_end(struct node*start){
	struct node * ptr = start;
	if(start==NULL)
	printf("\nUNDERFLOW\n");
	
	else{
		start=ptr->link;
		free(ptr);
	}
	traverse_sll(start);return start;
}
main()

	struct node * start =NULL;
	int op;
	start = create_sll(start);
	traverse_sll(start);
	do
	{
	   printf("\n Menu:\n1. Traverse. \n2. Insert_beg.\n3. Insert_end.\n4. Delete_beg.\n5. Delete_End\n6Exit.\nEnter your choice :");
	   scanf("%d",&op);
	   switch(op){
	   	case 1:traverse_sll(start);break;
	   	case 2:start=insert_beg(start);break;
	   	case 3:start=insert_end(start);break;
	   	case 4:start=delete_beg(start);break;
	   	case 5:start=delete_end(start);break;
	   	case 6:exit(0);
	   	
	   }	
	}while(op<7);
	
}
