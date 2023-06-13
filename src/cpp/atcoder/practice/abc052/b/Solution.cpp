#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n;
  cin >> n;
  string s;
  cin >> s;
  int res = 0;
  int cur = 0;
  rep(i, 1, n) {
    if (s[i-1] == 'I' ) {
      cur++;
      res = max(res, cur);
    } else if (s[i-1] == 'D') {
      cur --;
      res = max(res, cur);
    }
  }
  cout << res << endl;
	return res; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/