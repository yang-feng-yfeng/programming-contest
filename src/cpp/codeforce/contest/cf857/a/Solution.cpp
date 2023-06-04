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

const int NMAX = 110;
int add[NMAX], rem[NMAX];

ll solve() {
	int n; cin >> n;
	vector<int> b(n);
	int up = 0, down = 0;
	rep(i, 0, n-1) {
		cin >> b[i];
		if (b[i] > 0) {
			add[b[i]]++;
			up++;
		} else {
			down++;
			rem[-b[i]]++;
		}
	}
	// max
	rep(i, 1, up) {
		cout << i << " ";
	}
	rep(i, 1, down) {
		cout << up - i << " ";
	}
	cout << endl;
	//min
	rep(i, 1, down) {
		cout << "1" << " 0 ";
	}
	rep(i, 1, up-down) {
		cout << i << " ";
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