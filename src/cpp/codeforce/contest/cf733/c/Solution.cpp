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

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	// binary search from [0, n]
	int left = 0;
	int right = n+1;
	while (left < right) {
		int mid = (right + left) / 2;
		// cout << " mid: " << mid << endl;
		ll scoref = 100 * mid;
		ll scores = 0;
		int cnt = (mid + n) - floor((long double) 1.0 * (mid + n) / 4);
		// cout << "cnt : " << cnt << endl;
		for (int i = 0; i < cnt - mid; i++) {
			scoref += a[i];
		}
		for (int i = 0; i < min(n, cnt); i++) {
			scores += b[i];
		}

		// cout << "score1: " << scoref << " score2: " << scores << endl;
		if (scoref >= scores) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return right;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << res << endl;
	}

}
/********  Main() Ends Here *************/