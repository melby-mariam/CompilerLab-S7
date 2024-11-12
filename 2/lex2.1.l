%{
#include<stdio.h>
%}

%%
if|else|for|while|switch|char	{printf("Keyword:%s\n",yytext);}
[0-9]+	{printf("Number:%s",yytext);}
[=|+|-|*|/|%|<|>]	{printf("Operator:%s\n",yytext);}
[_]	{printf("Unknown:%s",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*	{printf("Identifier:%s\n",yytext);}

[0-9][a-zA-Z0-9]*	{printf("Unknown:%s\n",yytext);}
[+|_|/|%]*	{printf("Unknown:%s\n",yytext);}
[\t]+	
[\n] {return 0;}
.	{printf("Unknown:%s\n",yytext);}
%%

int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}
