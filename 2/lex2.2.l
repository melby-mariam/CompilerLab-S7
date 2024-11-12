%{
#include<stdio.h>
int char_count=0,word_count=0,line_count=0;
%}

%%
[ \t]	{char_count++;word_count++;}
[\n]	{char_count++;word_count++;line_count++;}
[\n][\n]	{return 0;}
.	{char_count++;}
%%

int main()
{
yylex();
printf("No.of line count:%d\n",++line_count);
printf("No.of word count:%d\n",++word_count);
printf("No.of line count:%d\n",char_count);
}

int yywrap()
{
return 1;
}
