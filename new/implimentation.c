#include<stdio.h>
#include "structure.h"
#include<stdlib.h>
#include <time.h>
#include<string.h>
void login(tree *t)
{
  
  //clrscr();
  system("clear");
  char str[100];
  int *cat[5];
  int barcode;
  int category,category1;
  float price;
  char date[9];
  char string[1000];
  float tax;
  int barcode1;
  FILE *fp;
  fp = fopen("file.txt", "a+");
  //fp=fopen("file.txt","r");
  while(!feof(fp))
  {
    fscanf(fp,"%s %d %d %f %f %s\n",str,&barcode1,&category,&price,&tax,date);
    //printf("%s %d %d %f %f %s\n",str,barcode1,category,price,tax,date);
    ins(t,barcode1,str,category,price,tax,date);
  }
  fclose(fp);
  fp=fopen("file.txt","a+");
  system("clear");
  printf("\n\n\n\n\n*******************************************************************************************************************\n");
  printf("*******************************************************************************************************************\n");
  int ch,ele,n1;
  while(1)
  { 
    printf("\n\n\n\n\n*******************************************************************************************************************\n");

    printf("Enter choice\n");
    printf("\n1.Add an item\n2.Remove an item\n3.Display the store inventory\n4.Access Element Category Wise\n5.Expired Items\n6.Exit\n");
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
       printf("Enetr element expiry date(dd/mm/yyyy)\n");
       scanf("%s",date);
       fprintf(fp,"%s %d %d %f %f %s\n",str,barcode,category,price,tax,date);
       ins(t,barcode,str,category,price,tax,date);
       fclose(fp);
       fp=fopen("file.txt","a+");
       system("clear");
       break;
       case 2:
        printf("Enter elements barcode which has to be deleted\n");
        scanf("%d",&barcode);
        del(t,barcode);
       break;
       case 3:if(emp(t))
            printf("No elements\n");
           else
            {
             system("clear");
             printf("\n\n\n\n\n*******************************************************************************************************************\n");
            trav(t);
            }
       break;
       case 4:printf("Enter category which you want to access\n");
              scanf("%d",&category1);
              category_function(t,category1);
              break;
       case 5:expir_items();
       break;
       case 6:return;
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
node * minValueNode(node* node1)
{
node* current = node1;
while (current->left != NULL)
 current = current->left;
return current;
}
void del(tree *t,int data)
{
t->root=deleteNode(t->root,data);
char str[100];
int *cat[5];
int barcode;
int category,category1;
float price;
char date[9];
char string[1000];
float tax;
int barcode1;
FILE *fp,*fp_new;
fp = fopen("file.txt", "a+");
fp_new=fopen("file2.txt","w+");
while(!feof(fp))
{
 fscanf(fp,"%s %d %d %f %f %s\n",str,&barcode1,&category,&price,&tax,date);
if(barcode1!=data)
 fprintf(fp_new,"%s %d %d %f %f %s\n",str,barcode1,category,price,tax,date);
    //ins(t,barcode1,str,category,price,tax,date);
}
remove("file.txt");
int ret;
char oldname[] = "file2.txt";
char newname[] = "file.txt";
fclose(fp_new);
fp_new=fopen("file.txt","w+");
fclose(fp_new);
ret = rename(oldname, newname);
}
node* deleteNode(node* root, int key)
{
if(root == NULL) 
 return root;
if(key < root->barcode)
 root->left = deleteNode(root->left, key);
else if(key > root->barcode)
 root->right = deleteNode(root->right, key);
else
{
 if(root->left == NULL)
  {
    node *temp = root->right;
    free(root);
    return temp;
   }
 else if (root->right == NULL)
  {
    node *temp = root->left;
    free(root);
    return temp;
  }
 node* temp = minValueNode(root->right);
 root->barcode = temp->barcode;
 root->right = deleteNode(root->right, temp->barcode);
}
return root;
}

void trav(tree *t)
{
printf("Bar_Code     Name     Expiry_Date           Category          MRP         TaxPrice\n");
iot(t->root);
printf("\n");
}
void iot(node *r)
{
if(r!=NULL)
{
iot(r->left);
/*
printf("Barcode :%d\n",r->barcode);
printf("Name    :%s\n",r->str);
printf("Category:%d\n",r->category);
printf("Price   :%f\n",r->price);
printf("Tax Per :%f\n",r->tax);
printf("Exp Date:%s\n",r->expdate);
printf("\n");
*/
printf("%d        %s         %s            %d         %f          %f\n",r->barcode,r->str,r->expdate,r->category,r->price,r->tax);
iot(r->right);
}
}
int emp(tree *t)
{
return(t->root==NULL);
}
int search(tree *t,int data)
{
node *p,*q,*temp;
p=t->root;
q=NULL;
if(p==NULL)
 return 0;
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
 return 0;
}
else
 return 1;
}
}
void create_link(START *s)
{
s->head=NULL;
s->c=0;
}
void ins_link(START *s,node *temp1)
{
ARLIST *temp,*temp2;
temp=(ARLIST *)malloc(sizeof(ARLIST));
temp->barcode=temp1->barcode;
temp->category=temp1->category;
temp->price=temp1->price;
temp->tax=temp1->tax;
strcpy(temp->expdate,temp1->expdate);
strcpy(temp->str,temp1->str);
temp->next=NULL;
temp2=s->head;
if(s->head==NULL)
{
 s->head=temp;
 s->c=s->c+1;
}
else
{
 while(temp2->next!=NULL)
 temp2=temp2->next;
 temp2->next=temp;
 s->c=s->c+1;
}
}
void add(tree *t,START *s,int data)
{
node *p,*q,*temp;
p=t->root;
q=NULL;
while(p!=NULL && p->barcode!=data)
{
q=p;
if(data<p->barcode)
 p=p->left;
else
 p=p->right;
}
ins_link(s,p);
}
void bill(START *s,tree *t)
{
int barcode;         
int category;
float price;
float tax;
char expdate[11];
char str[100];
float p;

ARLIST *temp;
temp=s->head;
system("clear");
printf("\n\n\n\n\n*******************************************************************************************************************\n");
printf("Bar_Code        Name          Expiry_Date         Category         MRP           TaxPrice      SubTotal\n");
float sum=0;
while(temp!=NULL)
{
p=((temp->tax/100.0)*temp->price)+temp->price;
sum=sum+p;

printf("%d          %s           %s           %d           %f        %f      %f\n",temp->barcode,temp->str,temp->expdate,temp->category,temp->price,temp->tax,p);
temp=temp->next;
}
printf("\n");
float z=sum;
if(sum>2500)
{
 printf("You have an offer of 10 percent\n");
 sum=0.9*sum;
}
 
printf("Total Bill=%f\n",sum);
printf("You have Saved :%f",z-sum); 
printf("\n");
printf("********************************************************Thank You Visit Again***************************************\n");
}
void category_function(tree *t,int category1)
{
printf("Bar_Code     Name     Expiry_Date     Category     MRP     TaxPrice\n");
node *temp=t->root;
iot1(temp,category1);
}
void iot1(node *r,int category1)
{
if(r!=NULL)
{
iot1(r->left,category1);
if(r->category==category1)
{
printf("%d    %s     %s     %d     %f     %f\n",r->barcode,r->str,r->expdate,r->category,r->price,r->tax);
}
iot1(r->right,category1);
}
}
void expir_items()
{
time_t t = time(NULL);
struct tm tm = *localtime(&t);
float d = 	(tm.tm_year + 1900) + ((float)(tm.tm_mon)/12) + ((float)(tm.tm_mday)/365);
printf("Current Date and Time:\n %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
printf("\n");
FILE *fp;
char str[100];
int *cat[5];
int barcode1;
int category,category1;
float price;
char date[9];
char string[1000];
float tax;
const char s[2] = "/";
char *token;
float year,month,day;
float temp;
fp=fopen("file.txt","r");
printf("**********************************The Expired Items are:**********************************************************\n");
while(!feof(fp))
{
	fscanf(fp,"%s %d %d %f %f %s\n",str,&barcode1,&category,&price,&tax,date);
	token = strtok(date, s);
	day = atof(token);
	token = strtok(NULL, s);
	month = atof(token);
	token = strtok(NULL, s);
	year = atof(token);
	temp = year + ((month-1)/12) + (day/365);
	if(temp < d)
	{
		printf("%s  barcode:%d \n",str,barcode1);
	}
}
}
