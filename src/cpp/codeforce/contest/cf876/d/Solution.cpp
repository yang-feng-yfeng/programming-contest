#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	vector<int> c(n);
	rep(i, 0, n-1) {
		cin >> c[i];
	}

	// find the longest non decreasing series
	map<int, vector<int>> series;
	rep(i, 0, n-1) {
		if (i+1 < n && c[i] < c[i+1]) {
			
		} else {
			if ( i - 1 >= 0 && c[i] > c[i-1]) {
				series.p
			}
		}
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/