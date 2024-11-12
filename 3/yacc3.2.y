%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE double

int yylex(void);
void yyerror(const char *msg);
%}

%token ID NL

%%
stmt : exp NL {printf("Valid identifier\n");exit(0);};
exp: ID;
%%

void yyerror(const char *msg)
{
printf("Invalid identifier\n");
}

int main()
{
printf("Enter the token : ");
yyparse();
return 0;
}

