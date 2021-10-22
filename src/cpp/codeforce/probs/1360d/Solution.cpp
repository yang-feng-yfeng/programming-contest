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

vector<int> primes;

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		ll n, k;
		cin >> n >> k;
		if (n <= k) {
			cout << "1" << endl;
			continue;
		}
		// if it's prime

		ll res = n;

		for (ll i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				if ( i <= k) {
					res = min (res, n/i);
				}
					
				if ( n/i <= k) {
					res = min(res, i);
				}
			}
		}
		cout << res << endl;
	}
	
}
/********  Main() Ends Here *************/