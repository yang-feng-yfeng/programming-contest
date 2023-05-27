#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n; cin >> n;
  vector<double> l(n), r(n);
  rep(i, 0, n-1) {
    int tmp;
    cin >> tmp >> l[i] >> r[i];
    if (tmp == 2) {
      r[i] -= 0.5;
    } else if (tmp == 3) {
      l[i] += 0.5;
    } else if (tmp == 4) {
      l[i] += 0.5;
      r[i] -= 0.5;
    }
  }

  int res = 0;
  rep(i, 0, n-1) {
    rep(j, i+1, n-1) {
      res += (max(l[i], l[j]) <= min (r[i], r[j]));
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