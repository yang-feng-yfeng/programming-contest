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
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	if (b >= 0) {
		// as many as possible
		return n * (a + b);
	} else {
		// as smaller as possible
		// minimize the operation count
		int fcnt = 0, scnt = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0' && s[i-1] == '1') {
				//  1 -> 0
				fcnt++;
			}
			if (s[i] == '1' && s[i-1] == '0') {
				scnt++;
			}
		}
		return n * a + (max(fcnt, scnt) + 1 ) * b;
	}

}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/