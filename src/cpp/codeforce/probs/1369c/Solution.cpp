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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), w(k);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> w[i];
		}
		ll res = 0;
		sort(w.begin(), w.end());
		sort(a.rbegin(), a.rend());
		int wstart = 0;
		int i = 0;

		while ( i < n ) {
			if ( i < k ) {
				res += a[i];
				if (w[i] == 1) {
					wstart++;
					res += a[i];
				}
				i++;
				continue;
			}
			int go = w[wstart]-1;
			res += a[i + go - 1];
			i += go;
			// cout << "i: " << i << endl;
			wstart++;
		}
		cout << res << endl;
	}
	
}
/********  Main() Ends Here *************/