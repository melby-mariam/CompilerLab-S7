%{
#include<stdio.h>
int vowel=0,cons=0;
%}

%%
[aeiouAEIOU]	{vowel++;}
[a-zA-Z]	{cons++;}
\n	{return 0;}
%%

int main()
{
yylex();
printf("No.of Vowels:%d\n",vowel);
printf("No.of consonants:%d\n",cons);
return 0;
}

int yywrap()
{
return 1;
}
