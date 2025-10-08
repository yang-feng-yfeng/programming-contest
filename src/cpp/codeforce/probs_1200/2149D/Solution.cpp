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


double median(vector<ll>& av) {
	if (av.size() % 2 == 0) {
		return (av[av.size()/2] + av[av.size()/2 -1]) * 1.0 / 2.0;
	} else {
		return av[av.size()/2];
	}
}

ll solve() {
	ll n;
	cin >> n;
	string a;
	cin >> a;
	ll a_sum = 0, b_sum = 0;
	ll ai = 0, bi = 0;
	vector<ll> av;
	vector<ll> bv;
	rep (i, 0, n-1) {
		if (a[i] == 'a') {
			av.push_back(i - ai); 
			ai++;
		} else {
			bv.push_back(i - bi);
			bi++;
		}
	}
	
	double a_med, b_med;
	double a_res = 0, b_res = 0;
	if (av.size() > 0) {
		a_med = median(av);
		// cout << "a_med " << a_med << endl;
		rep(i, 0, av.size()-1) {
			a_res += abs(av[i] - a_med);
		}
	} else {
		a_res = 1e6;
	}

	if (bv.size() > 0) {
		b_med = median(bv);
				// cout << "b_med " << b_med << endl;

		rep(i, 0, bv.size() - 1) {
			b_res += abs(bv[i] - b_med);
		}
	} else {
		b_res = 1e6;
	}
	return (ll)min(a_res, b_res);
	
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