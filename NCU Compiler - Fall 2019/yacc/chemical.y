%{
	#include <stdio.h>
	void yyerror(const char *message);
	char cnt[300];
%}

%code requires {
	typedef struct{
		int num[300];
	}Dict;
}

%union {
	Dict dict;
	int num;
	char elem;
}

%token <num> NUM
%token <elem> ELEM
%token ARROR
%type <dict> item
%type <dict> expr

%left ARROW
%left '+'
%nonassoc '(' ')'
%nonassoc MERGE
%nonassoc ELEM
%nonassoc NUM

%%

stmts   : stmts stmt
		| stmt
	
stmt 	: expr ARROW expr '\n' {
			int i;
			for(i=1; i<300; i++){
				int cnt = $1.num[i] - $3.num[i];			
				if(cnt < 0) cnt = -cnt;
				if(cnt > 0){
					printf("%c %d\n", (char)i, cnt);
				}
			}
		}
		| '\n'
		
expr	: NUM item {
			int i;
			for(i=1; i<300; i++){
				$$.num[i] = $2.num[i] * $1;
			}
		}
		| expr '+' expr {
			int i;
			for(i=1; i<300; i++){
				$$.num[i] = $1.num[i] + $3.num[i];
			}
		}
		| item { $$ = $1; }
        ;
		
		
item	: 
		  '(' item ')'  { $$ = $2; }
		| '(' item ')' NUM {
			int i;
			for(i=1; i<300; i++){
				$$.num[i] = $2.num[i] * $4;
			}
		}
		| item item %prec MERGE {
			int i;
			for(i=1; i<300; i++){
				$$.num[i] = $1.num[i] + $2.num[i];
			}
		}
		| ELEM NUM   	{ $$.num[(int)$1] += $2; }
		| ELEM			{ 
			$$.num[(int)$1] ++; 
		}
		;
		


%%
void yyerror (const char *message){
	printf ("%s\n", "invalid format");
	// fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
	yyparse();
	return(0);
}