#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   struct node *next;
   int data;
   char str[100];
}NODE;
typedef struct queue
{
  struct node *head;
}QUEUE;
void create(QUEUE *);
void enq(QUEUE *,int,char* str);
int emp(QUEUE *);
void deq(QUEUE *,int *,char* str);
void disp(QUEUE *,char* str);
void create(QUEUE *h)
{
  h->head=NULL;
}
void enq(QUEUE *h,int data,char* str)
{
  NODE *temp,*p;
  p=h->head;
  temp=(NODE *)malloc(sizeof(NODE));
  temp->data=data;
  temp->next=NULL;
  if(h->head==NULL)
    h->head=temp;
  else
  {
    while(p->next!=NULL)
       p=p->next;
    p->next=temp;
  }
}
void deq(QUEUE *h,int *ele,char* str)
{
NODE *p;
p=h->head;
*ele=h->head->data;
if(p->next==NULL)
{
free(p);
h->head=NULL;
}
else
{
h->head=p->next;
free(p);
}
}
void disp(QUEUE *h,char* str)
{
NODE *temp;
temp=h->head;
printf("%s\n",temp->str);
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
int emp(QUEUE *h)
{
  return(h->head==NULL);
}

void login()
{
  //clrscr();
  char str[100];
  printf("\n\n\n\n\n*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
  int ch,ele,n1;
  QUEUE h;
  create(&h);
  while(1)
  {
    printf("Enter choice\n");
    printf("\n1.Add an item\n2.Remove an item\n3.Display the store inventory\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
       printf("Insert an item along with its name\n");
       scanf("%s",str);
       scanf("%d",&ele);
       enq(&h,ele,str);
       break;
       case 2:
        if(emp(&h))
       {
         printf("Item appears to be empty do u want to place an order\n");
         scanf("%d",&n1);
         if(n1==1)
          printf("Order for the item will be placed\n");
       }
       else
       {
        deq(&h,&ele,str);
        printf("%d\n",ele);
       }
       break;
       case 3:if(emp(&h))
           printf("No elements\n");
         else
           disp(&h,str);
       break;
       case 4:return;
       break;
       default:printf("Invalid option\n");
  }
}
}
  
int main()
{
  int n,c=0;
  char str1[100];
  char str2[100];
  //clrscr();
  printf("\n\n\n\n\n\n*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
  printf("\t\t\t\t\tWELCOME TO BHATS AND BROS SUPERMARKET\n");
  printf("*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
do{
  printf("1.Admin\n2.Customer\nEnter your choice!!..\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1:
          printf("Enter your Username\n");
          scanf("%s",str1);
          if(strcmp(str1,"User") ==0)
          {
            do{
             printf("Enter your password\n");
             scanf("%s",str2);
             if(strcmp(str2,"123")==0)
             {
               printf("You have logged in\n");
               login();
             }
             else
             {
               c++;
               if(c==2)
               { 
                 printf("Unauthorized access\n");
                 exit(0);
               } 
             }
           }while(c<2); 
          }
          break;
   case 2:
        printf("Thank you\n");
        exit(0);
   default:
        exit(0);
  }
  }while(n<=2);
  return 0;
}
 
