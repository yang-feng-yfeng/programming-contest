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

ll solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	rep(i, 0, n-1) {
		cin >> a[i];
	}
	vector<vector<int>> matrix(n, vector<int>(n));
	rep(i, 0, n-1) {
		rep(j, i+1, n-1) {
			int diff = 0;
			rep(k, 1, m) {
				if (a[i][k-1] != a[j][k-1]) {
					diff++;
				}
			}
			if (diff == 1) {
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}
	set<int> passed;
	deque<int> next; 
	next.push_back(0);
	while (!next.empty()) {
		int i = next.front();
		passed.emplace(i);
		next.pop_front();
		rep(j, 0, n-1) {
			if (matrix[i][j] == 1 && passed.find(j) == passed.end()) {
				next.push_back(j);
			}
		}
	}
	if (passed.size() == n) {
		cout << "Yes" <<endl;
	} else {
		cout << "No" <<endl;
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	solve();
}
/********  Main() Ends Here *************/