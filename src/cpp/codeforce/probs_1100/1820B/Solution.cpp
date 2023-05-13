#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string a;
  cin >> a;
  int n = a.size();
  int start = 0, end = 0, mx = 0, tmp = 0;
  rep(i, 0, n - 1) {
    if (a[i] == '1') {
      tmp++;
    } else {
      mx = max(mx, tmp);
      tmp = 0;
    }
  }
  int i = 0;
  while (i < n - 1) {
    if (a[i] == '1') {
      start++;
      i++;
    } else {
      break;
    }
  }

  i = n - 1;
  while (i >= 0) {
    if (a[i] == '1') {
      end++;
      i--;
    } else {
      break;
    }
  }

  mx = max(mx, start + end);
  ll res;
  ll comp = static_cast<ll>((mx + 1) / 2);
  if (mx % 2 == 1) {
    res = comp * comp;
  } else {
    res = comp * (comp + 1);
  }

  return res;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/