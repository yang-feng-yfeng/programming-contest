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
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
using ll = long long; 

// ll calcNext(ll start, ll input) {
// 	ll next = start + 1;
// 	// cout << "start: " << start << endl;
// 	while (start <= input && start > 0) {
// 		start = start * pow(10, (int)log10(next)+1) + next;
// 		//cout << "start: " << start << endl;
// 		next++;
// 	}
// 	return start <= 0 ? LLONG_MAX : start;
// }

ll bs(ll input, ll l, ll r, int t) {
	//cout << "t: " << t << "l: " << l << " r: " << r << endl;
	if (l > r) {
		return LLONG_MAX;
	}
	if (r == l) {
		ll rn = r + 1;
		for (int i = 1; i < t; i++) {
			r = r * (ll)(pow(10, (ll)log10(rn)+1)) + rn;
			rn++;
		}
		return r > 0 && r > input? r : LLONG_MAX;
	}
	ll tl = l;
	ll tr = r;
	ll mid = tl + (tr - tl) / 2 ;
	ll tmid = tl + (tr - tl) / 2;
	ll midn = mid+1;
	for (int i = 1; i < t; i++) {
		// cout << " tmid: " << tmid << endl;
		// cout << "midn " << midn << endl;
		tmid = tmid * (ll) (pow(10, (int)log10(midn)+1)) + midn;
		
		//cout << "t: " << t << " tmid: " << tmid << endl;
		if (tmid < 0) {
			return bs(input, l, mid - 1, t);
		}
		midn++;
	}
	//cout << "t: " << t << " tmid: " << tmid << endl;
	if (tmid > input) {
		return bs(input, l, mid, t);
	} else {
		return bs(input, mid+1, r, t);
	}
}

ll solve(ll input) {
	int n = (int)log10(input) + 2;

	ll minValue = LLONG_MAX;
	for (int t = min(n, 14); t >= 2; --t) {
		int l = 1;
		int r = pow(10, ceil(n / t)) - 1;
		ll res = bs(input, l, r, t);
		minValue = min(minValue, res);
	}
	return minValue;
}

/********** Main()  function *******/
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		ll input;
		cin >> input;
		cout << "Case #" << t <<": " << solve(input) << endl;
	}
}
/********  Main() Ends Here *************/