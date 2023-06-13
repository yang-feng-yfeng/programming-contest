#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  ll a, b, x;
  cin >> a >> b >> x;
  ll res = (b / x) - (a / x);
  if (a % x == 0) {
    res ++;
  }
  cout << res << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/