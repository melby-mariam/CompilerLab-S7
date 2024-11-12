%{
#include<stdio.h>
char str[50];
%}

%%
\n	{strcat(str,"\n");}
abc	{strcat(str,"ABC");}
.	{strcat(str,yytext);}
\n\n	{return 0;}
%%

int main(){
yylex();
printf("%s\n",str);
return 0;
}

int yywrap()
{
return 1;
}
