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

int solve() {
	ll n, c;
	cin >> n >> c;
	vector<ll> a(n);
	rep(i, 0, n-1) {
		cin >> a[i];
		a[i] += i+1;
	}
	sort(a.begin(), a.end());
	int res = 0;
	int i = 0;
	while (i < n && c > 0) {
		c -= a[i];
		if ( c >= 0) {
			i++;
			res++;
		}
	}
	return res;
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