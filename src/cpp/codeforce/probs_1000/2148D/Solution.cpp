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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> odds;
	ll res = 0, evenSum = 0;
	rep(i, 0, n-1) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			odds.push_back(a[i]);
		} else {
			evenSum += a[i];
		}
	}
	if (odds.size() > 0) {
		res += evenSum;
		sort(odds.begin(), odds.end(), std::greater<int>());
		int i = 0;
		while (i < (odds.size()+1) / 2 ) {
			res += odds[i];
			i++;
		}
	}

	return res;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/