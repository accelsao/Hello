%{
	#include "y.tab.h"
	void yyerror(const char *);
	int pos = 0;
%}
%%
\n	{ return yytext[0]; }
[ \t]+	{ pos += yyleng; }
[0-9]+	{ pos += yyleng; yylval.num = atoi(yytext); return NUM; }
"+" { pos += yyleng; yylval.num = pos; return ADD; }
"-" { pos += yyleng; yylval.num = pos; return SUB; }
"*" { pos += yyleng; yylval.num = pos; return MUL; }
"^T" { pos += yyleng; return T; }
"("|")"|"["|"]"|"," { pos += yyleng; return yytext[0]; }
.	{ yyerror("invalid input"); return 0; }
%%

