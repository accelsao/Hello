int gen_base(int l, int r){
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	int base = uniform_int_distribution<int>(l+1, r)(mt_rand);
	return (base&1) ? base: base-1;
}
