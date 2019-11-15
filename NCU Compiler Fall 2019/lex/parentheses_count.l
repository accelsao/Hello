%{
int cnt=0;
int ls=0;
%}

%%

[{] {
	while(ls){
		printf("\t");
		ls--;
	}
	printf("%s", yytext);
	cnt++;
}
[}] {
	ls--;
	cnt--;
	while(ls){
		printf("\t");
		ls--;
	}
	printf("%s", yytext);
}
. {
	while(ls){
		printf("\t");
		ls--;
	}
	printf("%s", yytext);
}

\n {
	ls=cnt;
	printf("%s", yytext);
}

%%

int main(int argc, char *argv[]) {
	yylex();
	return(0);
}