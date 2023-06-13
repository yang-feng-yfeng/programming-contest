#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string s;
  cin >> s;
  int n = s.size();
  int res = 0;
  rep(i, 1, n-1) {
    if(s[i] != s[i-1]) {
      res ++;
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