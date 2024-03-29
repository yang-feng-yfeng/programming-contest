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
typedef numeric_limits<double> dbl;

double solve(int n, int l, vector<int>& a) {
	double d = -1;
	sort(a.begin(), a.end());
	d = max(d, (double)a[0]);
	for (int i = 1; i < n; i++) {
		d = max(1.0 * (a[i] - a[i-1])/2, d);
	}
	d = max(d, (double)(l - a[n-1]));
	return d;
}

/********** Main()  function *******/
int main()
{
	int n, l;
	cin >> n >> l;
	// for (int t = 1; t<=T; ++t ) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double res = solve(n, l, a);
	cout.precision(dbl::max_digits10);
	cout << res << endl;
	// }
}
/********  Main() Ends Here *************/