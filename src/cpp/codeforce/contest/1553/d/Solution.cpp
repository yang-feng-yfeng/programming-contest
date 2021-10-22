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

int solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	int j = m - 1;
	for (int i = n - 1; i >= 0;) {
		if (j == -1) {
			break;
		}
		if (s[i] == t[j]) {
			i--;
			j--;
		} else {
			i-=2;
		}
	}
	if (j == -1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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