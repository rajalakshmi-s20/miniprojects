#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void filebug(int id)
{
	printf("********** FILING A BUG ***********\n");
	time_t CurrentTime;
	time(&CurrentTime);
	char name[20], bugtype[50], bugdescription[1000], bugpriority[30];
	FILE* ptr;
	printf("Enter your name:\n");
	scanf("%s",name);
	char ids[10],ex[]=".txt";
	itoa(id,ids,10);
	strcat(name,ids);
	strcat(name,ex);
	printf("Filename:%s\n",name);
	ptr=fopen(name,"w");
	if (ptr==NULL)
		printf("cannot create file!\n");
	fprintf(ptr,"DATE AND TIME: %s",ctime(&CurrentTime));
    fprintf(ptr,"BUG ID: %d\n\n",id);
    printf("BUG ID:%d\n",id);
    fprintf(ptr,"BUG FILED BY: %s\n\n",name);
    printf("Enter bug type:\n");
    scanf(" %[^\n]s",bugtype);
    fprintf(ptr,"TYPE OF BUG: %s\n",bugtype);
    printf("Enter bug priority:\n");
    scanf(" %[^\n]s", bugpriority);
    fprintf(ptr,"BUG PRIORITY: %s\n",bugpriority);
    printf("Enter the bug description:\n");
    scanf(" %[^\n]s",bugdescription);
    fprintf(ptr,"BUG DESCRIPTION: %s\n",bugdescription);
	printf("\n Status of bug:");
	printf("\n 1.NOT YET ASSIGNED\n 2.IN PROCESS\n 3.FIXED");
	printf("\n 4.DELIVERED\n\n ENTER YOUR CHOICE:");
	int j;
	scanf("%d",&j);
	fprintf(ptr,"\nDATE AND TIME: %s",ctime(&CurrentTime));
	fprintf(ptr,"BUG STATUS: ");
	switch (j) 
	{
	case 1:
		fprintf(ptr,"NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(ptr,"IN PROCESS\n");
		break;
	case 3:
		fprintf(ptr,"FIXED\n");
		break;
	case 4:
		fprintf(ptr,"DELIVERED\n");
		break;
	default:
		printf(" invalid choice\n");
		fprintf(ptr,"DETECTED\n");
		break;
	}
	fclose(ptr);
}
void changestatus()
{
	printf("************ Change status ************\n");
	time_t CurrentTime;
	time(&CurrentTime);
	FILE* file;
	char name[50],ex[]=".txt";
	printf("Enter file name:\n");
	scanf("%s",name);
	strcat(name,ex);
	file=fopen(name,"a");
	printf("\n 1.NOT YET ASSIGNED\n 2.IN PROCESS\n 3.FIXED");
	printf("\n 4.DELIVERED\n\n ENTER YOUR CHOICE:");
	int k;
	scanf("%d",&k);
	fprintf(file,"\nDATE AND TIME: %s",ctime(&CurrentTime));
	fprintf(file,"BUG STATUS: ");
	switch (k) 
	{
	case 1:
		fprintf(file,"NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(file,"IN PROCESS\n");
		break;
	case 3:
		fprintf(file,"FIXED\n");
		break;
	case 4:
		fprintf(file,"DELIVERED\n");
		break;
	default:
		printf(" invalid choice\n");
		fprintf(file,"SAME STATE");
		break;
	}
	fclose(file);
}
void report()
{
	printf("\n************** REPORT **************\n");
	FILE* fp;
	char name[50],ex[]=".txt";
	printf("Enter file name:\n");
	scanf("%s",name);
	strcat(name,ex);
	fp=fopen(name,"r");
	char ch;
	ch=getc(fp);
	while (ch!=EOF)
	{
	printf("%c",ch);
	ch=getc(fp);
	}
	fclose(fp);
	getch();
}
void main()
{
	printf("************** BUG TRACKING SYSTEM **************\n");
	int number, i=1, id=0;
	while (i!=0) 
	{
		printf("\n 1.FILE A NEW BUG\n 2.CHANGE THE STATUS OF THE BUG");
		printf("\n 3.GET BUG REPORT\n 4.EXIT");
		printf("\n\n ENTER YOUR CHOICE:");
		scanf("%d",&number);
		switch (number) 
		{
		case 1:
			id++;
			filebug(id);
			break;
		case 2:
			changestatus();
			break;
		case 3:
			report();
			break;
		case 4:
			i=0;
			break;
		default:
			printf(" invalid choice\n");
			break;
		}
	}
}
