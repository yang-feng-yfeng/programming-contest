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
	return 0;
}

/********** Main()  function *******/
int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll x;
	cin >> x;

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > x) {
			cout << (i+1) << endl;
			return 0;
		}
	}
	ll res = 0;
	if (x > sum) {
		res += (x / sum) * n;
		x = x % sum;
	}

	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i-1];
		if (x < cur) {
			res += i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/