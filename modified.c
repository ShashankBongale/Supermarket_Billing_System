#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   struct node *left,*right;
   int barcode;         
   int category;
   float price;
   float tax;
   char expdate[11];
   char str[100];
}node;
typedef struct tree
{
node *root;
}tree;
void trav(tree *);
void iot(node *);
void ins(tree *,int ,char [],int ,float ,float ,char []);
void del(tree *,int );
void create(tree *);
void login();
int emp(tree *);
int main()
{
  int n,c=0;
  char str1[100];
  char str2[100];
  //clrscr();
  system("clear");
  printf("\n\n\n\n\n\n*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
  printf("\t\t\t\t\tWELCOME TO BHATS AND BROS SUPERMARKET\n");
  printf("*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
do{
  printf("\n");
  printf("Enter your choice!!..\n");
  printf("1.Admin\n2.Customer\n3.Exit\n");
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
               break;
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
   case 3:printf("Exit\n");
          exit(0);
   default:
        printf("Invalid Option Enter once again\n");
  }
  }while(n<=2);
  return 0;
}
void login()
{
  //clrscr();
  system("clear");
  char str[100];
  int barcode;
  int category;
  float price;
  char date[9];
  float tax;
  printf("\n\n\n\n\n*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
  int ch,ele,n1;
  tree t;
  create(&t);
  while(1)
  {
    printf("Enter choice\n");
    printf("\n1.Add an item\n2.Remove an item\n3.Display the store inventory\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
       printf("Enter Element name\n");
       scanf("%s",str);
       printf("Enter 6 digit element barcode\n");
       scanf("%d",&barcode);
       printf("Enter element Category\n");
       scanf("%d",&category);
       printf("Enter element Price\n");
       scanf("%f",&price);
       printf("Enter element Tax percentage\n");
       scanf("%f",&tax);
       printf("Enetr element expiry date\n");
       scanf("%s",date);
       ins(&t,barcode,str,category,price,tax,date);
       break;
       case 2:
        printf("Enter elements barcode whichhas to be deleted\n");
        scanf("%d",&barcode);
        del(&t,barcode);
       break;
       case 3:if(emp(&t))
            printf("No elements\n");
           else
            trav(&t);
       break;
       case 4:return;
       break;
       default:printf("Invalid option\n");
  }
}
}
void create(tree *t)
{
t->root=NULL;
}
void ins(tree *t,int barcode,char name[],int category,float price,float tax,char date[])
{
node *temp,*p,*q;
temp=(node *)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
temp->barcode=barcode;
strcpy(temp->str,name);
temp->category=category;
temp->price=price;
temp->tax=tax;
strcpy(temp->expdate,date);
if(t->root==NULL) 
 t->root=temp;
p=t->root;
q=NULL;
while(p!=NULL && p->barcode!=barcode)
{
q=p;
if(barcode<p->barcode)
 p=p->left;
else
 p=p->right;
}
if(p==NULL)
{
if(barcode<q->barcode)
 q->left=temp;
else
 q->right=temp;
}
}
void del(tree *t,int data)
{
node *p,*q,*temp;
p=t->root;
q=NULL;
if(p==NULL)
 printf("tree does not contain any elements\n");
else
{
while(p!=NULL && p->barcode!=data)
{
q=p;
if(data<p->barcode)
 p=p->left;
else
 p=p->right;
}
if(p==NULL)
{
 printf("Element not present\n");
}
else
{

 if(q==NULL)
 {
  temp=p->right;           //If Root elemented has to be deleted
  while(temp->left!=NULL)
 {
  temp=temp->left;
 }
  temp->left=p->left;
  t->root=p->right;
  free(p);
 }
 else if(p->left==NULL && p->right==NULL)
 { 
  if(p->barcode>q->barcode)
  {
   free(p);
   q->right=NULL;         
  }
  else
  {
  free(p);
  q->left=NULL;
  }
 }
 else if(p->left==NULL && p->right!=NULL)
 { 
  if(p->barcode>q->barcode)
  {
   q->right=p->right;
  }
  else  
  q->left=p->right;
  free(p);
 }
 else if(p->right==NULL && p->left!=NULL)
 { 
  if(p->barcode>q->barcode)
   q->right=p->left;
  else
   q->left=p->left;
  free(p);
 }
 else
 {
  temp=p->right;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  q->right=p->right;
  temp->left=p->left;
  free(p);
 }
}
}
}
void trav(tree *t)
{
iot(t->root);
printf("\n");
}
void iot(node *r)
{
if(r!=NULL)
{
iot(r->left);
printf("Barcode :%d\n",r->barcode);
printf("Name    :%s\n",r->str);
printf("Category:%d\n",r->category);
printf("Price   :%f\n",r->price);
printf("Tax Per :%f\n",r->tax);
printf("Exp Date:%s\n",r->expdate);
printf("\n");
iot(r->right);
}
}
int emp(tree *t)
{
return(t->root==NULL);
}
