#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  ll n;
  cin >> n;
  string lids;
  cin >> lids;
  vector<ll> a(n);
  ll res = 0, start = -1, tmpRes = 0, tmpMin = 1e6;
  // ll tmpMin = 1e6;
  // ll tmpRes = 0;
  // ll start = -1;
  rep(i, 0, n - 1) {
    cin >> a[i];
  }

  for (int i = n -1; i >= 0 ; i--) {
    if (lids[i] == '1') {
      start = i;
      tmpRes += a[i];
      tmpMin = min(tmpMin, a[i]);
    } else {
      if (start != -1) {
        tmpRes += a[i];
        tmpMin = min(tmpMin, a[i]);
        res += tmpRes - tmpMin;

        start = -1;
        tmpRes = 0;
        tmpMin = 1e6;
      }
    }
  }
  if (start != -1) {
    res += tmpRes;
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