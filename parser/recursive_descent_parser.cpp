#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
typedef long long ll;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;

string ts;
int idx, ts_sz, lbr_cnt;
vector<pair<string,string>> ans;

bool primary_stat();
bool primary_tail_stat();
bool match_ID();
bool call_STRLIT();
bool call_stmt();
bool match_LBR();

bool match_ID(){
	string z="";
	int start_idx=idx;
	while(idx<ts_sz){
		if(('A'<=ts[idx]&&ts[idx]<='Z') ||
		('a'<=ts[idx]&&ts[idx]<='z') ||
		(ts[idx]=='_') ||
		(start_idx<idx&&'0'<=ts[idx]&&ts[idx]<='9')){
			z+=ts[idx];
		}
		else{
			break;
		}
		idx++;
	}
	return z.size()?ans.push_back({"ID", z}),1: 0;
//	if(z.size()){
//		ans.push_back({"ID", z});
//		return 1;
//	}
//	else{
//		return 0;
//	}
}
bool match_DOT(){
//	if(ts[idx]=='.'){
//		ans.push_back({"DOT", "."});
//		idx++;
//		return 1;
//	}
	
	return ts[idx]=='.'?ans.push_back({"DOT", "."}), ++idx, 1:0;
	
//	return 0;
}
bool match_LBR(){
	
	if(ts[idx]=='('){
		ans.push_back({"LBR", "("});
//		cout<<idx<<endl;
		idx++;
		lbr_cnt++;
		if(!call_stmt())return 0;
//		cout<<idx<<endl;
		if(lbr_cnt>0&&ts[idx]==')'){
			ans.push_back({"RBR", ")"});
			lbr_cnt--;
			idx++;
			return primary_tail_stat();
		}
		else{
			return 0;
		}
	}
}
bool primary_stat(){
	return match_ID()&&primary_tail_stat();
}
bool primary_tail_stat(){
	if(idx>=ts_sz){
		return 1;
	}
	int start_idx=idx;
	if(lbr_cnt>0&&ts[idx]==')'){
		lbr_cnt--;
		return 1;
	}
	else if(match_DOT()){
		return match_ID()&&primary_tail_stat();
	}
	else{
		idx=start_idx;
		return match_LBR();
	}
}
bool call_STRLIT(){
	if(ts[idx]!='"')return 0;
	string z="";z+=ts[idx];
	int i=idx+1;
//	printf("call_stmt strlit before %d\n", i);
	while(i<ts_sz){
		z+=ts[i];
		if(ts[i]=='"'){
			break;
		}
		i++;
	}
//	printf("call_stmt strlit after %d\n", i);

	if(i<ts_sz){
		ans.push_back({"STRLIT", z});
		idx=i+1;
		return 1;
	}
	else{
		idx=i;
		return 0;
	}
	
}
bool call_stmt(){ //1 if success, otherwise invalid input
	if(idx>=ts_sz){
		return 1;
	}

	int start_idx=idx;
//	printf("call_stmt %d\n", idx);
	if(ts[idx]==')'){
		if(lbr_cnt>0){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(primary_stat()){
		return 1;
	}
	else{
		idx=start_idx;
//		printf("call_stmt strlit %d\n", idx);
		return call_STRLIT();
	}
}
bool call_stmts(){
	return idx>=ts_sz ? 1:(call_stmt() && call_stmts());
}
bool program(){
	return call_stmts();
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>ts){
		ans.clear();
		idx=0;
		lbr_cnt=0;
		ts_sz=ts.size();
		if(program()){
			for(const auto& str:ans){
				cout<<str.F<<" "<<str.S<<"\n";
			} 
		}
		else{
//			for(const auto str:ans){
//				cout<<str.F<<" "<<str.S<<"\n";
//			} 
			cout<<"invalid input\n";
		}
	}
}

/*
"test_string"
Test_ID
a(ab(a)("z!"))a
ID(ab(a!b)("!z!"))
printf.p("Helloworkd!").p()
)12(
((ab))
ID.ter("asdsd").a121s.p().cpp
ID.ter(")")
*/

