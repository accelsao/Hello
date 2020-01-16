%{
	#include "y.tab.h"
	void yyerror(const char *);
%}
%%
\n { return yytext[0]; }
"+"|"("|")" { return yytext[0]; }
[ \t]+ {}
[0-9]+ { yylval.num = atoi(yytext); return NUM; }
[A-Za-z] { yylval.elem = yytext[0]; return ELEM; }
"->" { return ARROW; }
. { yyerror("Invalid Input"); }
%%
