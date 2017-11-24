#include<stdio.h>
#include<stdlib.h>
#include "structure.h"
int main()
{
  tree t;
  create(&t);
  int n,c=0;
  char str1[100];
  char str2[100];
  int bc;
  float sum,k;
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
               login(&t);
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
   case 2:printf("Welcome to the billing system\n");
         FILE *fp;
         char str[100];
         int *cat[5];
         int barcode1;
         int category,category1;
         float price;
         char date[9];
         char string[1000];
         float tax;
        fp=fopen("file.txt","r");
	while(!feof(fp))
	{
	fscanf(fp,"%s %d %d %f %f %s\n",str,&barcode1,&category,&price,&tax,date);
	//printf("%s %d %d %f %f %s\n",str,barcode1,category,price,tax,date);
	ins(&t,barcode1,str,category,price,tax,date);
	}
          //tree t;
          bc=1;
          START s;
          //char z[10]="dssa";
          //tree *t,int barcode,char name[],int category,float price,float tax,char date[],int data,tree **k
          //ins(&t,4455,z,1,55,45,1111,1,&k);
          int barcode;
	  create_link(&s);
          while(bc==1)
          {
	  printf("Enter Bar code of the Item to be billed\n");
          scanf("%d",&barcode);
          if(search(&t,barcode))             //for searching a barcode for its presence.
  	  {
           add(&t,&s,barcode);
          }
          else
           printf("Element is not present\n");
          printf("If you want to continue billing press 1 or press any other integer to print the bill\n");
          scanf("%d",&bc);  
          }
          bill(&s,&t);
          break;
   case 3:printf("Exit\n");
          exit(0);
   default:
        printf("Invalid Option Enter once again\n");
  }
  }while(n<=2);
  return 0;
}

