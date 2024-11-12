%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE double

int yylex(void);
void yyerror(const char *s);
%}

%token DIGIT ID NL
%left '+''-'
%left '/''*'

%%
stmt : exp NL{printf("Valid identifier\n");exit(0);};
exp:exp'+'exp
  |exp'-'exp
  |exp'*'exp
  |exp'/'exp
  |'('exp')'
  |ID
  |DIGIT;
%%

void yyerror(const char *s)
{
printf("Invalid expression\n");
}

int main()
{
printf("\nEnter the expression : ");
yyparse();
return 0;
}
