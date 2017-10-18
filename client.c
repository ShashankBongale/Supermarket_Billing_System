#include<stdio.h>
#include<stdlib.h>
#include "structure.h"
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

