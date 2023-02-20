#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int a[10],size=5,item,f=-1,r=-1;
void main()
{
	int opt;
	do
	{
		printf("\n\nEnter your choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:insert();
				break;
			case 2:delete();
				break;
			case 3:display();
				break;
			case 4:exit(0);
				break;
			default:printf("Invalid choice!");
		}		
	}
	while(opt!=4);
}
void insert()
{
	if(f==(r+1)%size)
	{
		printf("Queue is full!");
	}
	else
	{
		printf("Enter the data:");
		scanf("%d",&item);
		if(f==-1 && r==-1)
		{
			f=0;
			r=0;
			a[r]=item;
		}
		else
		{
			r=(r+1)%size;
			a[r]=item;
		}
	}
}
void delete()
{
	if(f==-1)
	{
		printf("Queue is empty");
	}
	 else if(f==r)  
            {  
               printf("\nDeleted element is %d",a[f]);
		f=r=-1;
            }  
            else  
            {  
                printf("\nDeleted element is: %d\n",a[f]);
		f=(f+1)%size;  
                    
		}  
         
}
void display()
{
	int temp;
	temp=f;
	if(temp==-1 && r==-1)
	{
		printf("No element!");
	}
	else
	{
		printf("\nQueue elements are:\t");
		while(temp>-1)
		{
			printf("%d\t",a[temp]);
			if(temp==r)
			break;
			temp=(temp+1)%size;
		}
	}
}

