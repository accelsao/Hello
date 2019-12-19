%{
#include <stdio.h>
void yyerror(const char *message);
int stk[1000];
int top = 0;
int op1, op2;
int fail = 0;
%}

%union {
	int num;
}



%token <num> NUM
%token ADD
%token SUB
%token MUL
%token MOD
%token INC
%token DEC
%token LOAD
%token ERR

%%

program	:	stmts {
				if(top != 1 || fail){
					yyerror("Invalid format");
				}
				else{
					printf("%d\n", stk[1]);
				}
			}

stmts   :	stmts stmt
		|   stmt
		;

stmt    : 	expr '\n'
		|	'\n'
		;

expr	:	LOAD NUM { stk[++top] = $2; }
		|	ADD  {
				if(top < 2){
					fail = 1;
				}
				else{
					op1 = stk[top--];
					op2 = stk[top--];
					stk[++top] = op1 + op2;
				}			
			}
		|	SUB  {
				if(top < 2){
					fail = 1;
				}
				else{
					op1 = stk[top--];
					op2 = stk[top--];
					stk[++top] = op1 - op2;
				}			
			}
		|	MUL  {
				if(top < 2){
					fail = 1;
				}
				else{
					op1 = stk[top--];
					op2 = stk[top--];
					stk[++top] = op1 * op2;
				}			
			}
		|	MOD  {
				if(top < 2){
					fail = 1;
				}
				else{
					op1 = stk[top--];
					op2 = stk[top--];
					if(op2 == 0){
						fail = 1;
					}
					stk[++top] = op1 % op2;
				}			
			}
		|	INC  {
				if(top < 1){
					fail = 1;
				}
				else{
					stk[top]++;
				}			
			}
		|	DEC  {
				if(top < 1){
					fail = 1;
				}
				else{
					stk[top]--;
				}			
			}
		;


%%

void yyerror (const char *message){
	printf("%s\n", message);
}

int main(int argc, char *argv[]) {
	yyparse();
	return(0);
}
