/*Write a menu Deiven program to implement the circular queue by using the following menu
1)Insertion
2)Deletion
3)Display*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	int f,r,a[MAX];
}queue;
int isempty (queue *q)
{
if(q->f==-1)
return 1;
else
return 0;
}
int isfull(queue *q)
{
if(q->f==0 && q->r==MAX-1 || q->f==q->r+1)
return 1;
else
return 0;
}
void display(queue *q)
{
int i;
if(isempty(q))
{
 printf("\nQueue Empty");
}
else
{
printf("\nElements in the queue are:");
if(q->f<=q->r)
for(i=q->f;i<=q->r;i++)
printf("%d\t",q->a[i]);
else
{
	for(i=q->f;i<=MAX-1;i++)
		printf("%d\t",q->a[i]);
	for(i=0;i<=q->r;i++)
		printf("%d\t",q->a[i]);
}
printf("\n\n");
}
}
void insert(queue *q, int x)
{
if(isfull(q))
{
    printf("\nOVERFLOW");
}
else if(q->f==-1 && q->r==-1)
{
q->f=0;q->r=0;q->a[q->r]=x;
}
else if(q->r==MAX-1)
{
	q->r=0;
	q->a[q->r]=x;
}
else
{
q->r++;
q->a[q->r]=x;
}
display(q);
}
void delete(queue *q)
{
int x;
if(isempty(q))
{
    printf("\nUNDERFLOW");
	return;
}
x=q->a[q->f];
if(q->f==q->r)
q->f=q->r=-1;
else if (q->f==MAX-1)
q->f=0;
else
q->f++;
printf("Deleted Item=%d",x);
display(q);
}
void main()
{
queue q;
int item,option;
q.f=-1;q.r=-1;
do
{
printf("\nMENU:\n1->INSERT\n2->DELETE\n3->DISPLAY\nEnter your choice:");
scanf("%d",&option);
switch(option)
{
case 1: printf("\nEnter Item:");
        scanf("%d",&item);
        insert(&q,item);
		break;
case 2: delete(&q);
        break;
case 3: display(&q);
        break;
default:printf("\nInvalid Choice");
}
}
while(option<4);
}
