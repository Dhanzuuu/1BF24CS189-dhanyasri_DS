
#include<stdio.h>
struct node{
int data;
struct node *next;
}*head=NULL;
int count()
{
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->next!= NULL)
    {
        temp=temp->next;
        i++;
    }
    return(i);
}
struct node*create(int value)
{
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 if(temp==NULL)
 {
     printf("memory allocation failed");
     exit(0);
 }
 else{
    temp->data=value;
    temp->next=NULL;
 }
 return temp;
}
void insert_begin(int value)
{
    struct node*newnode;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(int value)
{
    struct node*newnode,*temp;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insert_pos(int value,int pos)
{
     struct node*newnode,*temp1,*temp2;
    newnode=create(value);
    int i=count();
    int c=1;
    if(pos==1)
    {
        insert_begin(value);
    }
    else if(pos>i+1)
    {
        printf("insertion is not possible\n");
        return;
    }
    else{
        temp1=head;
        while(c<=pos-1&&temp1 !=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        newnode->next=temp2->next;
        temp2->next=newnode;
        }
}
void delete_begin()
{
 struct node *temp;
 if(head==NULL)
   {
       printf("deletion is not possible");
   }
else
  {
  temp=head;
  head=head->next;
   free(temp);
  }
}
void delete_end()
{
struct node *temp1,*temp2;
if(head==NULL)
{
   printf("deletion is not possible");
}
else
{
  temp1=head;
while(temp1->next!=NULL)
{
  temp2=temp1;
  temp1=temp1->next;
}
  temp2->next=NULL;
  free(temp1);
}
}
void delete_spec_value(int key)
{
if (head == NULL)

{
printf("List is empty. Cannot delete.\n");
return;
}
struct node *temp1 = head;
struct node *temp2 = NULL;
if (temp1 != NULL && temp1->data == key)
{
head = temp1->next;
free(temp1);
printf("Element %d deleted.\n", key);
return;
}
while (temp1 != NULL && temp1->data != key)
{
temp2 = temp1;
temp1 = temp1->next;
}
if (temp1 == NULL)
{
printf("Element %d not found in the list.\n", key);
return;
}
temp2->next = temp1 ->next;
free(temp1);
printf("Element %d deleted.\n", key);
}
void display()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void main()
{
    int ch,pos,value,key;
    printf("\n1.insert begin \n2.insert end \n3.insert at given position \n4.delete begin \n5.delete end \n6.delete given value \n7.display \n8.exit\n");
    do{
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Enter the value:");
                scanf("%d",&value);
                insert_begin(value);
                break;
            }
        case 2:
            {
                printf("Enter the value:");
                scanf("%d",&value);
                insert_end(value);
                break;
            }
        case 3:
            {
                printf("Enter the pos and value:");
                scanf("%d %d",&pos,&value);
                insert_pos(value,pos);
                break;
            }
        case 4: delete_begin();
                  break;
        case 5: delete_end();
                   break;
       case 6: {printf("enter key value of a node you want to delete: ");
              scanf("%d",&key);
              delete_spec_value (key);
              break;
              }
       case 7:
            display();
            break;
        case 8:
            break;
        default: printf("\n your choice is wrong!...");
        }
    }while(ch!=8);
}
