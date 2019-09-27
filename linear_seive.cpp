vector<ll>prime;
ll spf[N];//smallest prime factor
bool isprime[N];
void seive(int n){
	fill(isprime, isprime+n, 1);
	isprime[0]=isprime[1]=0;
	for(ll i=2;i<n;i++){
		if(isprime[i]){
			prime.push_back(i);
			spf[i]=i;
		}
		for(const auto& j:prime){
			ll cur=j*i;
			if(cur>=n)break;
			if(j>spf[i])break;
			isprime[cur]=0;
			spf[cur]=j;
		}
	}
}

