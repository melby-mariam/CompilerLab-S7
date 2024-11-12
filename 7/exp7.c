#include<stdio.h>
#include<time.h>

void fun1(){
for (int i=0;i<5;i++)
	printf("Hello\n");
}

void fun2(){
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
}

void main(){
clock_t t1,t2;

t1=clock();
fun1();
t1=clock()-t1;
double time_taken1=((double)t1)/CLOCKS_PER_SEC;
printf(".......NORMAL LOOP......");
printf("\nTime taken : %fseconds\n",time_taken1);

t2=clock();
fun2();
t2=clock()-t2;
double time_taken2=((double)t2)/CLOCKS_PER_SEC;
printf(".......UNROLLED LOOP......");
printf("\nTime taken : %fseconds\n",time_taken2);

}
