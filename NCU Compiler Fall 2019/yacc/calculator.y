%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
%}
%union {
	float fval;
}
%token <fval> FNUMBER 
%type <fval> expr
%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc UMINUS

%%

stmts   : stmts stmt
		| stmt
	
stmt	: expr '\n' { printf("%.1f\n", $1); }
		| '\n'
        ;
		
expr	: expr '+' expr         { $$ = $1 + $3; }
		| expr '-' expr         { $$ = $1 - $3; }
		| expr '*' expr         { $$ = $1 * $3; }
		| expr '/' expr         { $$ = $1 / $3; }
		| '(' expr ')'          { $$ = $2; }
		| expr '^' expr         { $$ = pow($1, $3); }
		| '-' expr %prec UMINUS { $$ = - $2; }
        | FNUMBER 				
        ;

%%
void yyerror (const char *message)
{
	fprintf (stderr, "%s\n",message);
}

int main(int argc, char *argv[]) {
	yyparse();
	return(0);
}