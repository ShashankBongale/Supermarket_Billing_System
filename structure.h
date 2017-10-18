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
