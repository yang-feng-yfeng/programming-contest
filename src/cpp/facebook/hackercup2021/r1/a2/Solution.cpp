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
ll mod = 1e9+7;

ll solve() {
	int n;
	cin >> n;
	string w;
	cin >> w;
	if (n == 1) {
		return 0;
	}
	ll res = 0;
	ll cur = 0;
	ll prev = 0;
	unordered_map<char, int> mem;
	mem[w[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (w[i] == 'F'){
			mem['F']++;
			cur = prev;
 		}
		else if (w[i] == 'O') {
			cur = prev + mem['X'];
			mem['O'] += mem['F'] + mem['X'] + 1;
			mem['F'] = 0;
			mem['X'] = 0;
		}
		else if (w[i] == 'X') {
			cur = prev + mem['O'];
			mem['X'] += mem['F'] + mem['O'] + 1;
			mem['F'] = 0;
			mem['O'] = 0;
		}
		// cout << "cur: " << cur << endl;
		prev = cur % mod;
		res = (res + prev) % mod;
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/