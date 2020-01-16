

%{
%}

word [ ]*0[xX][0-9a-fA-F]{1,8}[ ]*\r\n

%%

{word}  {
	int i;
	for(i=0;i<yyleng;i++){
		if(yytext[i]!=' '){
			printf("%c", yytext[i]);
		}
	}
}
.
\n
%%

int main(void)
{
    yylex();
    return 0;
}
