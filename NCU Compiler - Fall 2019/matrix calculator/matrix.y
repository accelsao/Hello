%{
	#include <stdio.h>
	#include <string.h>
	void yyerror(const char *message);
	void semanticErr(const int col);
%}

%code requires {
	typedef struct{
		int row, col;
	}MAT;
}

%union {
	int num;
	MAT mat;
}

%token ADD
%token SUB
%token MUL
%token <num> NUM
%token T
%type <mat> expr
%type <mat> matx

%left <num> ADD SUB
%left <num> MUL
%right T

%%
line    : expr '\n'                  { printf("Accepted\n"); }                 
        ;
expr	: expr ADD expr         {
									if($1.row == $3.row && $1.col == $3.col){
										$$ = $1;
									}
									else{
										semanticErr($2);
										return 0;
									}
								}
		| expr SUB expr         {
									if($1.row == $3.row && $1.col == $3.col){
										$$ = $1;
									}
									else{
										semanticErr($2);
										return 0;
									}
								}
		| expr MUL expr         {
									if($1.col == $3.row){
										$$.row = $1.row;
										$$.col = $3.col;
									}
									else{
										semanticErr($2);
										return 0;
									}
								}
		| expr T         		{
									$$.row = $1.col;
									$$.col = $1.row;
								}
		| '(' expr ')'			{
									$$ = $2;
								}
		| matx
        ;
		
matx	: '[' NUM ',' NUM ']'   {
									$$.row = $2;
									$$.col = $4;
								}
		;

%%

void semanticErr(const int col){
	printf("Semantic error on col %d\n", col);
}
void yyerror(const char *message){
	fprintf(stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
	yyparse();
	return(0);
}