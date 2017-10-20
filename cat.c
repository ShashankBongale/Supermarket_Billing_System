#include<stdio.h>
#include<stdlib.h>
typedef struct list list;
typedef struct node node;

struct list
{
char cat[25];
node *head;
int ne;
};

struct node
{
int data;
node *next;
};

void initlist(list *l,int i);
void insertfront(list *l,int data);
int deleteelement(list *l,int data);
void display(list *l);
void distroy(list *l); 

void main()
{
list l[5];
int ch=0,ele,pos,del,c=0,i=0,x=1;
for(i=0;i<5;i++)
{
initlist(&l[i],i);
}
while(x)
{
printf("ENTER THE CATEGORY YOU WANT TO ACCCESS:   ");
scanf("%d",&c);
puts(l[c].cat);
while(ch<4)
{
printf("ENTER YOUR CHOISE\n0:INSERT   1:DISPLAY   2:DELETE ELEMENT   3:DISTROY   4:EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 0: printf("ENTER THE BAR CODE:");
        scanf("%d",&ele);
        insertfront(&l[c] ,ele);
        break;

case 1: display(&l[c]);
	break;

case 2: printf("ENTER THE BAR CODE:");
	scanf("%d",&ele);
	if(deleteelement(&l[c],ele))
	printf("%d is deleted.\n",ele);
	else
	printf("%d not found\n",ele);
	break;

case 3: distroy(&l[c]);
	break;
default:ch=10;
}
}
ch=0;
printf("If you want to EXIT press 0 else press 1.");
scanf("%d",&x);
}
}

void initlist(list *l,int i)
{
printf("ENTER THE CATEGORY NAME OF Si no. %d :   ",i);
gets(l->cat);
l->head=NULL;
l->ne=0;
}

void insertfront(list *l,int data)
{
node *temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;
if(l->head==NULL)
l->head=temp;
else
{
temp->next=l->head;
l->head=temp;
}
l->ne++;
return;
}



void display(list *l)
{
node *p=l->head;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
printf("\n");
return;
}


int deleteelement(list *l,int data)
{
node *p=l->head,*q;
if(l->head==NULL)
{
return 0;
}
if(l->head->data==data)
{
l->head=l->head->next;
free(p);
return 1;
}
while(p->next!=NULL && p->data!=data)
{
q=p;
p=p->next;
}

if(p->data==data)
{
q->next=p->next;
free(p);
return 1;
}
else
return 0;
}

void distroy(list *l)
{
node *p=l->head;
while(p!=NULL)
{
l->head=p->next;
free(p);
p=l->head;
}
return;
}

