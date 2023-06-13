#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int w, h, n;
  cin >> w >> h >> n;
  int wmin = 0, wmax = w, hmin = 0, hmax = h;
  int x, y, a;
  rep(i, 0, n - 1) {
    cin >> x >> y >> a;
    if (a == 1) {
      wmin = max(x, wmin);
    } else if (a == 2) {
      wmax = min(x, wmax);
    } else if (a == 3) {
      hmin = max(y, hmin);
    } else {
      hmax = min(y, hmax);
    }
  }

  int res = max(0, wmax - wmin) * max(0, hmax - hmin);
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