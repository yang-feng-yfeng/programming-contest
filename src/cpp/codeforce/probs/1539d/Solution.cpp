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

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<pair<ll, ll>> ba(n);
	for (int i = 0; i < n ; i++) {
		cin >> ba[i].second >> ba[i].first;
	}
	sort(ba.begin(), ba.end());
	ll res = ba[n-1].second;
	ll cur = 0;
	ll ans = 0;
	int i = 0;
	int j = n-1;
	for (int i = 0, j = n - 1; i <= j; i++) {
		while (i <= j && cur < ba[i].first) {
			ll t = min(res, ba[i].first - cur);
			cur += t;
			ans += 2 * t;
			res -= t;
			if (res == 0) {
				j--;
				res = ba[j].second;
			}
		}
		if (i > j) {
			break;
		}
		ll t = i == j ? res : ba[i].second;
		cur += t;
		ans += t;
	}
	cout << ans << endl;
	return 0;
}
/********  Main() Ends Here *************/