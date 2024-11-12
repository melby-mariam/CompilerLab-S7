%{
#include<stdio.h>
#include<stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER ID NL
%left '+''-'
%left '/''*'

%%
stmt : exp NL {printf("Value=%d\n",$1);exit(0);};
exp : exp'+' exp {$$=$1+$3;}
  |exp'-'exp {$$=$1-$3;}
  |exp'*'exp {$$=$1*$3;}
  |exp'/'exp {$$=$1/$3;}
  |'('exp')' {$$=$2;}
  |ID {$$=$1;}
  |NUMBER {$$=$1;};
%%

void yyerror(const char *s)
{
printf("invalid expression\n");
}

int main() {
printf("Enter the expression:");
yyparse();
return 0;

}
