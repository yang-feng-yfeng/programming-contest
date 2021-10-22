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
	int n;
	cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}

	int nbEven = 0, nbOdd = 0;
	for (int i = 0; i < 2*n; i++) {
		if (a[i] % 2 == 0) {
			nbEven++;
		} else {
			nbOdd++;
		}
	}
	if (nbEven == nbOdd) {
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