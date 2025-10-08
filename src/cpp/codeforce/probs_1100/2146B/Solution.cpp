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
#define rep(i, l, r) for (ll i = l; i <= r; i++)

bool check(vector<int> & a, int m) {
	rep(i, 1, m) {
		if (a[i] == 0) {
			return false;
		}
	}
	return true;
}

string solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m+1, 0);
	vector<vector<int>> ls(n);
	int t=0;
	rep (i, 0, n-1) {
		int l;
		cin >> l;
		int tmp;
		rep (j, 0, l-1) {
			cin >> tmp;
			ls[i].push_back(tmp);
			if (a[tmp] == 0) t++;
			a[tmp]++;
		}
	}
	if (t != m) return "no";
	int cnt = 1;
	rep(i, 0, n-1) {
		rep(j, 0, ls[i].size() - 1) {
			a[ls[i][j]]--;
			if (a[ls[i][j]] == 0) {
				t--;
			}
		}
		if (t == m) cnt++;
		rep(j, 0, ls[i].size() - 1) {
			if (a[ls[i][j]] == 0) {
				t++;
			}
			a[ls[i][j]]++;
		}
		if (cnt >= 3) {
			return "yes";
		}
	}

	return "no";
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		string res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/