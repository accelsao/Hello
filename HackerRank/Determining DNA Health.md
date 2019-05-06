AC¦Û°Ê¾÷
```cppp
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Assume that each string consists of lowercase English alphabetic letters only

const int SIGMA = 26;

struct Node{
	vector<int> idx;
	Node* next[SIGMA];//next
	Node* fail;
	Node() :fail(NULL) {
		for (int i = 0; i < SIGMA; i++) {
			next[i] = NULL;
		}
	}
};
class ACTree {
public:
	Node* root;
	ACTree() {
		root = new Node;
		root->fail = root;
	}
	void addNode(const string &s, int idx);
	void buildFailPointer();
	long long search(const string& s, const int& l, const int& r);
	Node* get_next(Node* cur, int k);
};
vector<int> cost;
int main() {
	// construct trie
	ACTree tree;
	int n;
	cin >> n;
	vector<string> p(n); // pattern
	cost.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		tree.addNode(p[i], i);
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	tree.buildFailPointer();
	int q;
	cin >> q;
	long long L = 1e18, R = 0;
	while (q--) {
		int l, r;
		string t; // text
		cin >> l >> r >> t;
		long long z = tree.search(t, l, r);
		L = min(L, z);
		R = max(R, z);
	}
	cout << L << " " << R << endl;
}

void ACTree::addNode(const string& s, int idx){
	int n = s.size();
	Node* cur = root;
	for (int i = 0; i < n; i++) {
		int k = s[i] - 'a';
		if (cur->next[k] == NULL) {
			cur->next[k] = new Node;
		}
		cur = cur->next[k];
	}
	cur->idx.push_back(idx);
	return;
}

void ACTree::buildFailPointer(){
	queue<Node*>q;
	q.push(root);
	Node* cur, * child;
	while (q.size()) {
		cur = q.front(); q.pop();
		for (int k = 0; k < SIGMA; k++) {
			child = cur->next[k];
			if (child) {
				q.push(child);
				if (cur == root) {
					child->fail = root;
				}
				else {
					child->fail = get_next(cur->fail, k);
				}
				child->idx.insert(child->idx.end(), child->fail->idx.begin(), child->fail->idx.end());
			}
		}
	}
}

long long ACTree::search(const string& s, const int& l, const int& r){
	long long ans = 0;
	Node* cur = root;
	for (size_t i = 0; i < s.size(); i++) {
		cur = get_next(cur, s[i] - 'a');
		for (const auto& x : cur->idx) {
			if (x >= l && x <= r) {
				ans += cost[x];
			}
		}
	}
	return ans;
}

Node* ACTree::get_next(Node* cur, int k){
	if (!cur->next[k]) {
		if (cur == root)
			cur->next[k] = root;
		else
			cur->next[k] = get_next(cur->fail, k);
	}
	return cur->next[k];
}

/*
6
a b c aa d b
1 2 3 4 5 6
3
1 5 caaab
0 4 xyz
2 4 bcdybc
*/

```