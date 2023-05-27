#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  ll n, m;
  cin >> m >> n;
  vector<ll> dis;
  vector<ll> a(n);
  rep(i, 0, n - 1) { cin >> a[i]; }
  sort(a.begin(), a.end());
  rep(i, 1, n - 1) { dis.push_back(a[i] - a[i - 1] - 1); }
  dis.push_back(a[0] + m - a[n - 1] - 1);
  sort(dis.begin(), dis.end(), greater<>());
  ll res = 0;
  int t = 0;
  rep(i, 0, dis.size() - 1) {
    if (dis[i] - 2 * t >= 2) {
      int tmp = dis[i] - 2 * t - 1;
      res += tmp;
	  t+=2;
    } else if (dis[i] - 2 * t == 1) {
      int tmp = dis[i] - 2 * t;
      res += 1;
	  t++;
    } else {
      break;
    }
  }
  return m - res;
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