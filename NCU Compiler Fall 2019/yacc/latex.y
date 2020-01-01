%{
	#include <stdio.h>
	#include <math.h>
	void yyerror(const char *message);
%}

%union{
	float num;
}

%token<num> NUM
%type<num> expr
%token FRAC
%left '+' '-'
%right '^'
%nonassoc FRACS

%%

stmts   : stmts stmt
		| stmt
	
stmt	: expr '\n' { printf("%.3f\n", $1); }
		| '\n'
        ;

expr : expr '+' expr { $$ = $1 + $3; }
	 | expr '-' expr { $$ = $1 - $3; }
	 | expr '^' expr { $$ = pow($1, $3); }
	 | expr '^' '{' expr '}' { $$ = pow($1, $4); }
	 | FRAC '{' expr '}' '{' expr '}' %prec FRACS { $$ = $3 / $6; }
	 | NUM
	 ;

%%

void yyerror(const char *message){
	fprintf(stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
	yyparse();
	return(0);
}
