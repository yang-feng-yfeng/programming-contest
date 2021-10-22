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
	int n;
	cin >> n;
	vector<int> a(2 * n + 1, 1e6);
	for (int i = 1; i <= n ; i++ ){
		int x;
		cin >> x;
		a[x] = i;
	}	
	ll res = 0;
	for (int x = 3 ; x < 2 * n; x++) {
		for (int i = 1; i <= sqrt(x); i++) {
			if ( x % i == 0 && x != i* i  && (a[i] + a[x / i])== x) {
				res ++;
			}
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
		
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/