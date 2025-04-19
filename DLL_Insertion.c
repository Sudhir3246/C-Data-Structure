#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *prev,*next;
};
struct node * create(struct node * start)
{
	struct node * new;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	printf("OverFlow");
	else
	{
		printf("Enter item:\n");
		scanf("%d",&item);
		new->info= item;
		new->prev= NULL;
		new->next= NULL;
	}
	return(start);
}
void traverse(struct node * start){
	struct node *ptr = start;
	printf("Double Linked List Contains :");
	while( ptr != NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
struct node * insert_beg(struct node * start)
{
	struct node *new;
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
			new->next = start;
			start->prev = new;
			start = new;
		}
		traverse(start);
	}
	return(start);
}
 struct node * insert_loc(struct node *start)
 {
 struct node *new,*ptr,*ptr1;
 int item,i=1,loc;
 printf("\nEnter item and loc:\n");
 scanf("%d%d",&item,&loc);
 new=(struct node *)malloc(sizeof(struct node));
 if(new==NULL)
 printf("\nOVERFLOW\n");
 else
 {
 new->info=item;
 new->prev=NULL;
 new->next=NULL;
 if(start==NULL)
 start=new;
 else { ptr1=start;
 while(i<loc&&ptr1!=NULL)
 {
 ptr=ptr1;
 ptr1=ptr1->next;i++;
 }
 if(ptr1==NULL)
 printf("\nLoc not found\n");
 else if(ptr1==start)
 { new->next=ptr;ptr->prev=new;start=new; }
 else
 {
 ptr->next=new;
 new->prev=ptr;
 new->next=ptr1;
 ptr1->prev=new;
 } } 
} traverse(start); return (start); }

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
		ptr = start;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next = new;
			new->prev = ptr;
		}
		traverse(start);
	}
	return(start);
}
struct node* delete_beg(struct node * start){
	struct node *ptr;
	if(start == NULL)
	printf("\nUnderFlow\n");
	else
	{
		ptr = start;
		printf("\n Item Deleted\n");
		start = ptr->next;
		start->prev=NULL;
		traverse(start);
		free(ptr);
	}
	return(start);
	}
	
struct node * delete_loc(struct node *start)
 {
 struct node *ptr,*ptr1;
 int i=0,loc;
 printf("\nEnter the loc of deletion:\n");
 scanf("%d",&loc);
 if(start==NULL)
 printf("\nUNDERFLOW\n");
 else {
 ptr1=start;
 while(i<loc&&ptr1!=NULL) {
 ptr=ptr1;
 ptr1=ptr1->next;i++;
 }
 if(ptr1==NULL)
 printf("\nLOC NOT FOUND\n");
 else if(ptr1==start) {
 start=start->next;
 start->prev=NULL; }
 else if(ptr->next==NULL)
 ptr->next=NULL;
 else {
 ptr->next=ptr1->next;
 ptr1->next->prev=ptr; }
 traverse(start); free(ptr);
 }
 return (start);
 }

struct node * delete_end(struct node * start){
	struct node *ptr;
	if(start==NULL)
	printf("UnderFlow");
else
{
 ptr=start;
 while (ptr->next!=NULL)
 ptr=ptr->next;
 printf("\nItem Deleted:%d",ptr->info);
 ptr->prev->next=NULL;
 ptr->prev = NULL;
 traverse(start);
 free(ptr);	
}
return(start);
}
//MAIN FUNCTION 		
main()
{
	struct node *start = NULL;
	int op;
	start=create(start);
    do
    {
    	printf("\nMenu:\n1.Traverse.\n2.Insert_Beg\n3.Insert_loc\n4.Insert_End\n5.Delete_beg\n6.Delete_loc\n7.Delete_end\n8.Exit");
    	printf("\nEnter Your Choice:\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:traverse(start);
			break;
    		case 2:start=insert_beg(start);
			break;
			case 3:start=insert_loc(start);
			break;
    		case 4:start=insert_end(start);
			break;
			case 5:start=delete_beg(start);
			break;
			case 6:start=delete_loc(start);
			break;
			case 7:start=delete_end(start);
			break;
			case 8:exit(0);
		}
	}
while(op<9);
}
      
