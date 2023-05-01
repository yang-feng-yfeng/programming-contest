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


ll digitSum(ll input) {
	ll sum = 0;
	while (input > 0) {
		sum += input % 10;
		input = input / 10;
	}
	return sum;
}


pair<ll,ll> solveSub(ll n) {
	if (n % 2 == 0) {
		return make_pair(n/2, n/2);
	} else {
		if ( n % 10 != 9) {
			return make_pair((n + 1)/ 2, (n - 1)/ 2);
		} else {
			auto res = solveSub(n/10);
			ll d1 = digitSum(res.first);
			ll d2 = digitSum(res.second);
			if (d1 > d2) {
				return make_pair(res.first * 10 + 4, res.second * 10 + 5);
			} else {
				return make_pair(res.first * 10 + 5, res.second * 10 + 4);
			}
		}
	}
}

pair<ll, ll> solve() {
	ll n;
	cin >> n;
	return solveSub(n);
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		pair<ll, ll> res = solve();
		cout << res.first << " " << res.second << endl;
	}
}
/********  Main() Ends Here *************/