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
	ll n, k, x;
	cin >> n >> k >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> diff;
	for (int i = 1; i < n; i++) {
		ll d = a[i] - a[i-1];
		if (d > x) {
			diff.push_back(d);
		}
	}

	sort(diff.begin(), diff.end());
	ll res = diff.size() + 1;
	ll rm = k;
	for (int i = 0; i < diff.size(); i++) {
		ll need = (diff[i] - 1) / x;
		if (need <= rm) {
			res --;
			rm -= need;
		} else {
			break;
		}
		if (res == 1) {
			break;
		}
	}
	cout << res << endl;
}
/********  Main() Ends Here *************/