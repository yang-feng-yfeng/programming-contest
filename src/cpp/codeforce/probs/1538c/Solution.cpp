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
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll res = 0;

	sort(a.begin(), a.end());

	int ref = 0;
	while (ref < n) {
		int vl = lower_bound(a.begin(), a.end(), l - a[ref]) - a.begin();
		int vr = lower_bound(a.begin(), a.end(), r - a[ref] + 1) - a.begin();
		res += (vr - vl);
		if (vl <= ref && ref < vr) {
			res -= 1;
		}
		// cout << "vl: " << vl << " vr: " << vr << " res : " << res << endl;
		ref++;
	}


	return res / 2;
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