#include<stdio.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];

void main(){
FILE *fp1,*fp2;
char f[100];
printf("Enter the input file name : ");
scanf("%[^\n]s",f);
fp1=fopen(f,"r");
fp2=fopen("output.txt","w");

while(fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result)!=EOF){
	if(strcmp(op,"+")==0){
		fprintf(fp2,"MOV R0,%s\n",arg1);
		fprintf(fp2,"ADD R0,%s\n",arg2);
		fprintf(fp2,"MOV %s,R0\n",result);
	}
	if(strcmp(op,"*")==0){
		fprintf(fp2,"\nMOV R0,%s\n",arg1);
		fprintf(fp2,"MUL R0,%s\n",arg2);
		fprintf(fp2,"MOV %s,R0\n",result);
	}
	if(strcmp(op,"-")==0){
		fprintf(fp2,"\nMOV R0,%s\n",arg1);
		fprintf(fp2,"SUB R0,%s\n",arg2);
		fprintf(fp2,"MOV %s,R0\n",result);
	
	}
	if(strcmp(op,"/")==0){
		fprintf(fp2,"\nMOV R0,%s\n",arg1);
		fprintf(fp2,"DIV R0,%s\n",arg2);
		fprintf(fp2,"MOV %s,R0\n",result);
	
	}
	if(strcmp(op,"=")==0){
		fprintf(fp2,"\nMOV R0,%s\n",arg1);
		fprintf(fp2,"MOV %s,R0\n",result);
	}
}
fclose(fp1);
fclose(fp2);
getchar();
}

