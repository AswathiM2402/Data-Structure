#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *root=NULL,*ptr=NULL,*new=NULL,*ptr1=NULL,*parent=NULL,*p=NULL;

void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(struct node*);
void delete(int);
void main()
{
   int opt,x;
   do
    {
       printf("\n\n1.Insert \n2.Inorder \n3.Preorder \n4.Postorder \n5.Search \n6.Delete \n7.Exit \n");
	printf("\nEnter your choice:");
       scanf("%d",&opt);
       switch(opt)
{
          case 1: insert();
 break;
 case 2: inorder(root);
 break;
 case 3: preorder(root);
 break;
 case 4: postorder(root);
 break;
 case 5: search(root);
 break;
 case 6: printf("\nEnter the element to be deleted:");
 scanf("%d",&x);
 delete(x);
 break;
 case 7: exit(0);
 break;
 default:printf("Invalid");
}

    }
  while(opt!=7);
}

void insert()
{
    int key;
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted:");
    scanf("%d",&key);
    if(new==NULL)
{
 printf("Insufficient memory");
}
    else
{
 new->prev=NULL;
 new->next=NULL;
          new->data=key;
 if(root==NULL)
    {
                root=new;          
             }
 else{
          ptr=root;
 while(ptr!=NULL)
          {
 if(key==ptr->data)
   {
printf("Item present in the tree");
break;
   }
 else if(key>ptr->data)
{
                  ptr1=ptr;
 ptr=ptr->next;
}
      else
{
ptr1=ptr;
ptr=ptr->prev;
}
 }
     
     if(ptr==NULL)
{
          if(key>ptr1->data)
ptr1->next=new;
 else
ptr1->prev=new;
}
}
}    
}

void inorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
    inorder(ptr->prev);
    printf("%d\t",ptr->data);
    inorder(ptr->next);
    }
}

void preorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
     printf("%d\t",ptr->data);
     preorder(ptr->prev);
     preorder(ptr->next);
    }
}

void postorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
     postorder(ptr->prev);
     postorder(ptr->next);
     printf("%d\t",ptr->data);
    }
}

void search(struct node *ptr)
{
    int data ,flag=0;
    if(ptr==NULL)
     printf("\nEmpty tree");
    else{
 printf("Enter the element to be found:");
 scanf("%d",&data);
 while(ptr!=NULL)
   {
if(data==ptr->data)
{
printf("\nElement found");
ptr=NULL;
    flag=1;
                }
                else if(data>ptr->data)
  ptr=ptr->next;
       else
   ptr=ptr->prev;
   }
       
         if(flag==0)
            printf("\nElement not found");
       }
}

void delete(int x)
{
int data;
if(root==NULL)
{
           printf("\nTree is empty");
        }
    else{
      parent=NULL;
      ptr=root;
      while(ptr!=NULL)
      {
if(ptr->data==x)
  break;
parent=ptr;
if(x>ptr->data)
  {
              ptr=ptr->next;
          }
else
          {
  ptr=ptr->prev;
          }
     }
     if(ptr==NULL)
      {
printf("Item not present");
      }
else{
      if(ptr->next==NULL&&ptr->prev==NULL)
      {
if(parent==NULL)
  {
            root=NULL;
          }
else if(parent->next==ptr)
  {
                    parent->next=NULL;
                  }
        else{
  parent->prev=NULL;
}
printf("Element deleted");
      free(ptr);
    }
    else if(ptr->next!=NULL && ptr->prev!=NULL)
    {
      p=ptr->next;
    while(p->prev!=NULL)
    {
      p=p->prev;
    }
     data=p->data;
     delete(p->data);
     ptr->data=data;
    }
    else if(ptr->next!=NULL && ptr->prev==NULL || ptr->next==NULL && ptr->prev!=NULL)
    {
    if(parent==NULL)
    {
if(ptr->next==NULL)
  {
root=ptr->prev;
   }
else{
            root=ptr->next;
        }
    }
    else
    {
if(parent->next==ptr)
{
 if(ptr->next==NULL)
parent->prev=ptr->prev;
 else
parent->next=ptr->next;
        }
        else
{
  if(ptr->prev==NULL)
parent->prev=ptr->next;
  else
    parent->prev=ptr->prev;
        }
    }
    printf("Element deleted");
    free(ptr);
    }
}
}
}
