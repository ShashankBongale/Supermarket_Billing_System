#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
time_t t = time(NULL);
struct tm tm = *localtime(&t);
float d = 	(tm.tm_year + 1900) + ((float)(tm.tm_mon)/12) + ((float)(tm.tm_mday)/365);
printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

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
printf("the expired items are:\n");
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
