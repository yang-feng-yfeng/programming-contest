#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>

using namespace std;
using ll = long long;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

// the idea is to re-place the desired piece to each vertex in order, with leaves processed first
// first step: find order from leaves using dfs and store them in a queue
// second step: reverse the first step result, and then find the appropiate place using dfs, and switch the positions

int solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, 0, n-1) { cin >> p[i]; p[i]--;}

	int m;
	cin >> m;
	vector<vector<pair<int,int>>> adj(n);
	rep(i, 0, m-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	vector<bool> vis(n);
	vector<int> q(n);
	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		q.push_back(u);
		for (auto [v, j]: adj[u]) {
			if (!vis[v]) {
				dfs(v);
			}
		}
	};
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	reverse(q.begin(), q.end());
	vector<int> ans;
	vector<bool> ok(n);
	for (auto s: q) {
		vis = ok;
		function<bool(int)> find = [&](int u) {
			vis[u] = true;
			if (p[u] == s) {
				return true;
			} 
			for (auto [v, j] : adj[u]) {
				if (!vis[v]) {
					if (find(v)) {
						ans.push_back(j);
						swap(p[u], p[v]);
						return true;
					}
				}
			}
			return false;
		};
		if (!find(s)) {
			cout << "-1\n";
			return 0;
		}
		ok[s] = true;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < int(ans.size()); i++) {
		cout << ans[i] + 1 << " \n"[i == int(ans.size()) - 1];
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/