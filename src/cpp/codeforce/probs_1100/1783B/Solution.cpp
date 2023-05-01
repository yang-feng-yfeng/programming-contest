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

int solve() {
	int n;
	cin >> n;
	int t = 1;
	int k = 0;
	rep(i, 0, n-1) {
		vector<int> temp(n);
		rep(j, 0, n-1) {
			if (k++ % 2 == 0) {
				temp[j] = t;
			} else {
				temp[j] = n * n - t + 1;
				t++;
			}
		}
		if (i % 2 == 0) {
			rep(j, 0, n-1) {
				cout << temp[j] << " ";
			}
		} else {
			rep(j, 0, n-1) {
				cout << temp[n-1 - j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/