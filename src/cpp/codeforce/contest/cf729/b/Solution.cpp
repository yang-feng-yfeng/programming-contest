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
#include <unordered_set>


using namespace std;
using ll = long long;
unordered_map<int, bool> mem;

bool inSet(int n, int a, int b) {
	if ((n - 1 ) % b == 0) {
		return true;
	}
	if (a == 1) {
		return ((n - 1 ) % b == 0);
	}
	// for (int i = 1; i < a; i++) {
	// 	int re = n - i * b;
	// 	// cout << "re: " << re << endl;
	// 	while (re > 0 && re % a == 0) {
	// 		if (inSet(re /a , a, b)) {
	// 			return true;
	// 		}
	// 		re -= a * b;
	// 	}
	// }
	// return false;

	ll pow = 1;
	while (pow > 0 && pow <= n) {
		if ((n - pow) % b == 0) {
			return true;
		}
		pow *= a;
	}
	return false;
}

int solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (inSet(n, a, b)) {
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