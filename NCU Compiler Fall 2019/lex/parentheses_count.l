%{
int cnt=0;
%}

line ^[^\n]*$

%%

{line} {
	int i;
	for(i=0;i<cnt;i++){
		printf("\t");
	}
	for(i=0;i<yyleng;i++){
		if(yytext[i]!='\t'){
			printf("%c", yytext[i]);
		}
		else if(yytext[i]=='{'){
			cnt++;
		}
		else if(yytext[i]=='}'){
			cnt--;
		}
	}
}

%%

int main(int argc, char *argv[]) {
	yylex();
	return(0);
}