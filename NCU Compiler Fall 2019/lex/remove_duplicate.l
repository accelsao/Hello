

%{
    #include <bits/stdc++.h>
	using namespace std;
	void func(char* yytext){
		string str(yytext);
		string res="";
		for(int i=0;i<str.size();i++){
			if(res.size()==0 || res.back()!=str[i]){
				res+=str[i];
			}
		}
		cout<<res<<"\n";
	}
%}

str [0-9a-zA-Z]+

%%

{str}  {
	func(yytext);
}
.
\n 
%%

int main(){
    yylex();
    return 0;
}
