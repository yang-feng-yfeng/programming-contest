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
	int n ; cin >> n;
	vector<int> a(n);
	rep(i, 0, n-1) {
		cin >> a[i];
	}
// 
	if( a[n-1] == 1) {
		// no;
		cout << "NO" << endl;
		return -1;
	}
	vector<int> res;
	int lastone = 0;
	for (int i = n-1; i>=0; i--) {
		if (a[i] == 0) {
			if (lastone == 0) {
				if ((i-1 >=0 && a[i-1] == 0) || i == 0) {
					res.push_back(0);
				}
			} else {
				// 110
				int k = lastone;
				while (k > 0) {
					res.push_back(0);
					k--;
				}
				res.push_back(lastone);
				lastone = 0;
				if ((i-1 >=0 && a[i-1] == 0) || i == 0) {
					res.push_back(0);
				}
			}
		} else {
			if (a[i] == 1) {
				lastone++;
			}
		}
	}
	if (lastone > 0) {
		int k = lastone;
		while (k > 0) {
			res.push_back(0);
			k--;
		}
		res.push_back(lastone);
	}
	cout << "YES" << endl;
	rep (i, 0, n-1) {
		cout << res[i] << " ";
	}
	cout << endl;
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
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/