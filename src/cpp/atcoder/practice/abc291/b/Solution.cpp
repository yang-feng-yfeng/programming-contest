#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n ; cin >> n;
  vector<int> a(5*n);
  rep(i, 0, 5*n-1) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int res = 0;
  rep(i, n, 4*n-1) {
    res += a[i];
  }
  cout << res * 1.0 / (3 * n) << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/