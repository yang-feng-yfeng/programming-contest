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

ll solve(ll n, ll k, ll prev) {
	if (n == 1) {
		return prev + 1;
	}
	if (n <= k+1) {
		return prev+ 2;
	}
	if (n > k+1 && n <= (2*k+1)) {
		return prev+ 3;
	}
	return solve(n - 2*k, k, prev+2);
}

ll solve() {
	int n,k;
	cin >> n >> k;
	return solve(n, k, 0);
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