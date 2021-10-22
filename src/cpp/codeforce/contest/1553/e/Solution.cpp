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

int cycle_count(vector<int> q, int n) {
	for (int i = 0; i < n; i++) {
		q[i] --;
	}
	vector<int> used(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		int j = i;
		while (used[j] == 0) {
			used[j] = 1;
			j = q[j];
		}
		ans++;
	}
	return ans;
}

bool check(int n, int m, int k, vector<int> p) {
	vector<int> q;
	for (int i = k; i < n; i++) {
		q.push_back(p[i]);
	}
	for (int i = 0; i < k; i++) {
		q.push_back(p[i]);
	}zz
	return n - cycle_count(q, n) <= m ;
}

int solve() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];

	vector<int> k(n);
	for (int i = 0; i < n; i++) {
		int idx = (i + n - p[i] + 1) % n;  
		k[idx]++;
	}
	vector<int> res;
	for (int i = 0; i < n; i++) {
		// cout << "k[i]: " << k[i] << "\n";
		if (k[i] + 2 * m >= n && check(n, m, i, p)) {
			res.push_back(i);
		}
	}

	cout << res.size();
	for (int i = 0; i < res.size(); i++) {
		cout << " " << res[i];
	}
	cout << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/