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

bool same(vector<int> &a, vector<int>& cp, int f, int s) {
	vector<int> first, second;

	for ( int i = f; i <= s; i++) {
		first.push_back(a[i]);
		second.push_back(cp[i]);
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	for (int i = 0; i < first.size(); i++) {
		if (first[i] != second[i]) {
			return false;
		}
	}
	return true;
}

void no() {
	cout << "NO" << endl;
}

int solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> p(n);
	for (int i = 0; i < m; ++i) {
		int pos;
		cin >> pos;
		p[pos - 1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (p[i] == 0) continue;
		int j = i;
		while (j < n && p[j]) ++j;
		sort(a.begin() + i, a.begin() + j + 1);
		i = j;
	}
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		ok &= a[i] <= a[i + 1];
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
	}
}
/********  Main() Ends Here *************/