#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node *next;	
};
struct node *top=NULL;
struct node *temp=NULL;
void main()
{
	int ch;
	do
	{
		printf("\nEnter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
			default:printf("Invalid entry");
		}
	}
	while(ch!=4);
}
void push()
{
	struct node *new=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted:");
	scanf("%d",&new->data);
	new->next=top;
	top=new;
	temp=top;
}
void pop()
{
	struct node *ptr;
	if(top==NULL)
	printf("\nStack underflow");
	else
	{
		printf("\nThe popped element is\t%d",top->data);
		ptr=top;
		top=top->next;
		free(ptr);
	}	
}
void display()
{
	
	if(top==NULL)
	printf("\nStack underflow");
	else
	{
		while(top!=NULL)
		{
			printf("%d\t",top->data);
			top=top->next;
		}
	}
	top=temp;
}

