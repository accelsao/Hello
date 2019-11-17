#include <bits/stdc++.h>
#define DEBUG
#define F first
#define S second
#define PB push_back
#define SZ(x) ((int)(x.size()))
#define ALL(X) (X).begin(), (X).end()
using namespace std;

set<char> firstSet[300];
vector<string> rules[300];

void ConstructfirstSet(int i){
	for(const string& str: rules[i]){
#ifdef DEBUG
		printf("Lhs(%d): %s\n", i, str.c_str());
#endif
		int j=0, len=SZ(str);
		while(j<len){
			if(('a'<=str[j]&&str[j]<='z')||str[j]=='$'){
				firstSet[i].insert(str[j]);
				break;
			}
			else if(str[j]==';'){
				if(j+1==len){
					firstSet[i].insert(';');
				}
			}
			else { /*A-Z*/
				int k=str[j];
				if(!SZ(firstSet[k])){
					ConstructfirstSet(k);
				}
#ifdef DEBUG
				printf("End of Construct Set(%c), SZ: %d\n", str[j], SZ(firstSet[k]));
				for(const char& ch: firstSet[k]){
					printf("%c", ch);
				}
				puts("");
#endif				
				assert(SZ(firstSet[k]));
				auto it=firstSet[k].find(';');

#ifdef DEBUG
				printf("Constructing Set(%c) ...\n current str = %s, current char = %c, lens of rules = %d\n", (char)i, str.c_str(), str[j], len);
#endif
				
				if(it==firstSet[k].end() || j+1==len){

					firstSet[i].insert(ALL(firstSet[k]));
					break;
				}
				else{
					set<char> tmp = firstSet[k];
					tmp.erase(tmp.find(';'));
#ifdef DEBUG
					printf("Set(%c) excluding ';' :", (char)k);
					for(const char& ch: tmp){
						printf(" %c", ch);
					}
					puts("");
//					exit(0);
#endif
					firstSet[i].insert(ALL(tmp));
				}
#ifdef DEBUG
			printf("Set %d insert to Set %d", k, i);
#endif	
				
			}
			j++;
		}


	}
	
#ifdef DEBUG
		printf("End of Construct Set(%c)\n", (char)i);
#endif
}
int main(){
	string grammar, rule;
	while(cin >> grammar, grammar != "END_OF_GRAMMAR")	{
		cin >> rule;
		char ch = grammar[0];	
		size_t pos=0;
		while((pos = rule.find("|")) != -1){
#ifdef DEBUG
			cout << "pos: " << pos << endl;
#endif
			rules[ch].PB(rule.substr(0, pos));
			rule = rule.substr(pos+1);
#ifdef DEBUG
			cout << "rule: " << rule << endl;
#endif
		}
		rules[ch].PB(rule);
	}
#ifdef DEBUG
	for(int i='A';i<='Z';i++)
		if(SZ(rules[i])){
			cout<<char(i)<<endl;
			for(auto x:rules[i])
				cout<<x<<" ";
			cout<<"\n";
		}
#endif
	for(int i='A';i<='Z';i++){
		ConstructfirstSet(i);
	}
#ifdef DEBUG
	puts("Answer: \n");
#endif
	
	
	for(int i='A';i<='Z';i++){
		if(SZ(firstSet[i])){
			printf("%c ", (char)i);
			for(const char& ch: firstSet[i]){
				printf("%c", ch);
			}
			puts("");
		}
	}
	puts("END_OF_FIRST");
}
/*
S ABC
A a|Cb|;
B C|dA|;
C e|f|;
END_OF_GRAMMAR 

S AC$
C c|;
A aBCd|BQ
B bB|;
Q q|;
END_OF_GRAMMAR 


S aBDh
B cC
C bC|;
D EF
E g|;
F f|;
END_OF_GRAMMAR

S AaAb|BbBa
A ;
B ;
END_OF_GRAMMAR 

*/


