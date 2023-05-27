#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n ; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) {
    cin >> a[i];
  }
  int res = INT_MAX;
  
  rep(i, -100, 100) {
    int local = 0;
    rep(j, 0, n-1) {
      local += (a[j] - i) * (a[j] - i);
    }
    res = min(res, local);
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