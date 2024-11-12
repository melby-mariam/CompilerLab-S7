#include<stdio.h>
#include<string.h>
int i,j,k,z,c=0;
char a[20],ac[20],act[20],stk[20];
void check();
void main()
{
	puts("GRAMMAR is :\nE->E+E\nE->E*E\nE->(E)\nE->id");
	puts("\nEnter input string : ");
	scanf("%s",a);
	c=strlen(a);
	strcpy(act,"SHIFT->");
	puts("Stack \t Input \t Action");
	
	for(k=0,i=0;j<c;k++,i++,j++)
	{
		if(a[j]=='i' && a[j+1]=='d')
		{
			stk[i]=a[j];
			stk[i+1]=a[j+1];
			stk[i+2]='\0';
			a[j]=' ';
			a[j+1]=' ';
			printf("\n$%s\t%s$\t%s",stk,a,act);
			check();
		}
		else
		{
			stk[i]=a[j];
			stk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%s symbols",stk,a,act);
			check();
		}
	}
	
	if(strcmp(stk,"E")==0 && a[0]==' ')
	{
		printf("\n$%s\t%s$\tACCEPT\n",stk,a);
	}
}
	
void check()
{
	strcpy(ac,"REDUCE TO E");
	for(z=0;z<c;z++)
	{
		if(stk[z]=='i' && stk[z+1]=='d')
		{
			stk[z]='E';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			j++;
		}
	}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			i=i-2;
		}
	}	
}

