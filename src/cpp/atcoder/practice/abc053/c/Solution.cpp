#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  ll x;
  cin >> x;
  if (x <= 6) {
    return 1;
  }
  ll m = x / 11LL;
  ll rmd = x % 11LL;
  ll res = m * 2LL + ((rmd > 6) ? 2 : ((rmd == 0) ? 0 : 1));
  return res;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << solve() << endl;
}
/********  Main() Ends Here *************/