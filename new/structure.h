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
typedef int ele_t;
struct ar_list
{
   int barcode;         
   int category;
   float price;
   float tax;
   char expdate[11];
   char str[100];
struct ar_list *next;
};
typedef struct ar_list ARLIST;
struct start
{
ARLIST *head;
int c;
};
typedef struct start START;
void trav(tree *);
void iot(node *);
void ins(tree *,int ,char [],int ,float ,float ,char []);
void del(tree *,int );
void create(tree *);
void login(tree *);
int emp(tree *);
int search(tree *t,int );
float billing(tree *t,int );
void create_link(START *);
void ins_link(START *,node *);
void add(tree *,START *,int );
void bill(START *,tree *);
void category_function(tree *,int );
void iot1(node *,int);
node* deleteNode(node* , int );
node* minValueNode(node* );
void expir_items();
