#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
const ll mod = 1e9 + 7;

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  rep(i, 0, n - 1) { cin >> a[i]; }

  if (n % 2 == 0) {
    vector<int> cnt(n / 2);
    rep(i, 0, n - 1) {
      if (a[i] % 2 == 0) {
        return 0;
      }
      cnt[a[i] / 2]++;
    }
    rep(i, 0, n / 2 - 1) {
      if (cnt[i] != 2) {
        return 0;
      }
    }
  } else {
    vector<int> cnt(n / 2 + 1);
    rep(i, 0, n - 1) {
      if (a[i] % 2 != 0) {
        return 0;
      }
      cnt[a[i] / 2]++;
    }
    rep(i, 1, n / 2) {
      if (cnt[i] != 2) {
        return 0;
      }
    }
    if (cnt[0] != 1) return 0;
  }
  ll res = 1;
  rep(i, 1, n / 2) { res = res * 2 % mod; }

  return res;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << solve() << endl;
}
/********  Main() Ends Here *************/