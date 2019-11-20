/*
str[0:z[i]]=str[i:i+z[i]]
*/
vector<int>z_f(const string &s){
	int n=SZ(s);
	vector<int>z(n);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]])z[i]++;
		if(i+z[i]-1>r){
			l=i,r=i+z[i]-1;
		}
	}
	return z;
}
