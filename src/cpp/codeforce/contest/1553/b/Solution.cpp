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
	string a, b;
	cin >> a >> b;
	string rev = a;
	reverse(rev.begin(), rev.end());
	int n = a.size();
	int m = b.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i && j < m ; j++) {
			// rest 
			string s = "";
			int r = m - j;
			s += a.substr(i, j);
			// cout << " s1 : " << s << endl;
			s += rev.substr(n - i - j - 1, m - j);
			// cout << " s : " << s << endl;
			if (s == b) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return -1;
	// for (int i )
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