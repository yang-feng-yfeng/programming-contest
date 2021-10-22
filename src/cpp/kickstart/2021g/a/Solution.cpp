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

bool solve() {
	ll n,d,c,m;
	cin >> n >> d >>c >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			if ( c > 0) {
				c--;
			} else {
				for ( ; i < n; i++) {
					if (s[i] == 'D') {
						return false;
					}
				}
				return true;
			}
		} else if (s[i] == 'D') {
			if ( d > 0) {
				d--;
				c += m;
			} else {
				return false;
			}
		}
	}
	return true;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		bool res = solve();
		cout << "Case #" << (t+1) << ": " << (res ? "YES" : "NO") << endl;
	}
}
/********  Main() Ends Here *************/