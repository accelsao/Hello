%{
	#include "y.tab.h"
%}
%%
\n	{ return yytext[0]; }
[ \t]+ {}
[0-9]+("."[0-9]+)? { yylval.num = atof(yytext); return NUM; }
"\\frac" { return FRAC; }
. { return yytext[0]; }
%%
