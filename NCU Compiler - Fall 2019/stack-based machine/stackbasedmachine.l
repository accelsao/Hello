%{
#include "y.tab.h"
void yyerror(const char *message);
%}
%%
\n	{ return yytext[0]; }
[ \t]+	{ /* do nothing */ }
"-"?[0-9]+	{ yylval.num = atoi(yytext); return NUM; }

"add" { return ADD; }
"sub" { return SUB; }
"mul" { return MUL; }
"mod" { return MOD; }
"inc" { return INC; }
"dec" { return DEC; }
"load" { return LOAD; }
.	{ yyerror("Invalid format"); exit(0); }

%%
