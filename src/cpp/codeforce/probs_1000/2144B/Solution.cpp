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
	int n ;
	cin >> n;
	vector<int> a(n);
	vector<int> t(n+1, 0);
	int cnt_zero=0, l=-1, r=-1, tmp, zero_idx;
	rep (i, 0, n-1){
		cin >> tmp;
		a[i] = tmp;
		if (tmp == 0) {
			cnt_zero++;
			zero_idx = i;
		}
		t[tmp]++;
 	}
	
	if (cnt_zero == 1) {
		rep(i, 1, n) {
			if (t[i] == 0) {
				a[zero_idx] = i;
			}
		}
	}

	rep(i, 1, n) {
		if (a[i-1] != i) {
			if (l==-1) l =i;
			r = i;
		}
	}
	return (r == l) ? 0 : (r - l + 1);
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