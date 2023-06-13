#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int k, s;
  cin >> k >> s;
  ll res = 0;
  rep(x, 0, k) {
    rep(y, 0, k) {
      auto z = s - x - y;
      if (z <= k && z >= 0) {
        res++;
      }
    }
  }
  cout << res << endl;
	return res; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/