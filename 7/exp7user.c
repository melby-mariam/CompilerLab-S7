#include<stdio.h>
#include<time.h>
char str[50];
void fun1(char *str){
for (int i=0;i<5;i++)
printf("%s\n",str);
}

void fun2(char *str){
printf("%s\n",str);
printf("%s\n",str);
printf("%s\n",str);
printf("%s\n",str);
printf("%s\n",str);
}

void main(){
clock_t t1,t2;
printf("Enter the string:");
scanf("%s",str);
t1=clock();
fun1(str);
t1=clock()-t1;
double time_taken1=((double)t1)/CLOCKS_PER_SEC;
printf("....normal loop....\n");
printf("Time taken : %fseconds\n\n",time_taken1);

t2=clock();
fun2(str);
t2=clock()-t2;
double time_taken2=((double)t2)/CLOCKS_PER_SEC;
printf("...unrolled loop...\n");
printf("Time taken : %fseconds\n\n",time_taken2);
}

