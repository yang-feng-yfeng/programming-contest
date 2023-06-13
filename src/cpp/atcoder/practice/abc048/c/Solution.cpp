#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  ll res = 0;
  rep(i, 0, n-1) {
    cin >> a[i];
    if (i > 0) {
      if (a[i] + a[i-1] > x) {
        ll diff =   a[i] + a[i-1] - x;
        res += diff;
        a[i] = max(0LL, a[i] - diff);
      }
    }
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