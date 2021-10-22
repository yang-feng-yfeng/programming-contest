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
ll mod = 1e9 + 7;

ll solve() {
	vector<ll> div {2, 3, 2, 5, 7, 3, 11, 13, 2 ,17, 19, 23, 5, 3, 29, 31, 2, 37, 41, 43, 47, 7, 51};
	ll n, res = 0;
	cin >> n;
	for (int i = 0; i < div.size() && n >= 1; i++) {
		res = (res + (n / div[i]) * div[i] % mod) % mod;
		n -= n/ div[i];
	}
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
	}
}
/********  Main() Ends Here *************/