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

ll solve() {
	ll n ;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	ll res = 0;
	for (ll i = 1; i < n; i++) {
		res -= (a[i] - a[i-1]) * (n - i) * i;
	}
	res += a[n-1];
	return res;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/