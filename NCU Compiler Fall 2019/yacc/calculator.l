%{
#include "y.tab.h"
%}
%%
\n {return yytext[0];}
[ \t]+ {}
[0-9]+("."[0-9]+)? { yylval.fval = atof(yytext);return(FNUMBER); }
. { return(yytext[0]); }
%%
