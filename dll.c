#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void insert_end();
void insert_mid();
void del_begin();
void del_end();
void del_mid();
void display();
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *new=NULL;
struct node *temp=NULL;
void main()
{
	int n,i,opt;
	printf("\n...Doubly Linked list creation...");
	printf("\nEnter the number of nodes to be created:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter the data to be inserted:");
		scanf("%d",&new->data);
		new->next=NULL;
		new->prev=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			new->prev=ptr;
			ptr->next=new;
		}
	}
	do
	{
		printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at middle\n4.Delete at the beginning\n5.Delete at the end\n6.Delete at the middle\n7.Display\n8.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:insert_begin();
				break;

			case 2:insert_end();
				break;

			case 3:insert_mid();
				break;

			case 4:del_begin();
				break;
			case 5:del_end();
				break;
			case 6:del_mid();
				break;
			case 7:display();
				break;
			case 8:exit(0);
				break;
			default:printf("Invalid choice");
		}
	}
	while(opt!=8);
}
void insert_begin()
{
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data to be inserted:");
	scanf("%d",&new->data);
	new->next=NULL;
	new->prev=NULL;
	new->next=head;
	head=new;
}
void insert_end()
{
	new=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted:");
	scanf("%d",&new->data);
	new->next=NULL;
	new->prev=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		new->prev=ptr;
		ptr->next=new;
	}
}

void insert_mid()
{
	int key;
	printf("Enter the key:");
	scanf("%d",&key);
	new=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted:");

	scanf("%d",&new->data);
	new->next=NULL;
	new->prev=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL && ptr->data!=key)
		{
			ptr=ptr->next;
		}
	}
	if(ptr->next==NULL)
	{
		ptr->next=new;
		new->next=ptr;
	}
	else
	{
		temp=ptr->next;
		new->next=temp;
		new->prev=ptr;
		ptr->next=new;
		temp->prev=new;
	}
}
void display()
{
	printf("\nList is: ");
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
void del_begin()
{
	if(head->next!=NULL)
	{
		printf("\n%d is deleted",head->data);
		head=head->next;
	}
}
void del_end()
{
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	if(ptr->next==NULL)
	{
		temp=ptr->prev;
		temp->next=NULL;
		ptr->prev=NULL;
		printf("\n%d is deleted",ptr->data);
	}
}


void del_mid()


{
	int key;
	printf("\nEnter the data to be deleted:");
	scanf("%d",&key);
	if(head->data==key)
	{
		head=head->next;
	}
	temp=head;
	ptr=head->next;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			temp->next=ptr->next;
			temp->prev=ptr->prev;
			free(ptr);
			printf("\n%d is deleted",key);
		}
		else
		{
			temp=ptr;
			ptr=ptr->next;
		}
	}
}
