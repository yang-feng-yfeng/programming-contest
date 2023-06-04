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
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n;
	cin >> n;
	vector<pair<int,ll>> a(n);
	rep(i, 0, n-1) {
		cin >> a[i].first;
		cin >> a[i].second;
		a[i].second = -a[i].second;
	}
	sort(a.begin(), a.end());

	int i = 0;
	int curA = 0;
	int totA = 0;
	ll res = 0;
	while (i < n) {
		if (i == 0) {
			curA = a[i].first;
			totA = a[i].first - 1;
			res -= a[i].second;
		} else {
			if (a[i].first == curA && totA > 0) {
				totA --;
				res -= a[i].second;
			} else if (a[i].first > curA) {
				curA = a[i].first;
				totA = a[i].first - 1;
				res -= a[i].second;
			}
		}
		// cout << "res: " << res << endl;
		i++;
	}
	return res;
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