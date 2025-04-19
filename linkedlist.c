#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create(struct node *start)
{
int item;
struct node*new;
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
printf("\nOverFlow");
else
{
printf("\n Enter Item: ");
scanf("%d", item);
new->info=item;
new->link=NULL;
if(start==NULL)
start=new;
}
return start;
}
void traverse(struct node * start)
{
	struct node*ptr=start;
	printf("\n SLL contains");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
}

int  main(){
	
}



