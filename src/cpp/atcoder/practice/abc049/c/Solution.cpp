#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  int cur = 0;
  while (cur < n) {
    if (s.substr(cur, 5) == "maerd" || s.substr(cur, 5) == "esare") {
      cur += 5;
    } else if (s.substr(cur, 6) == "resare") {
      cur += 6;
    } else if (s.substr(cur, 7) == "remaerd") {
      cur += 7;
    } else {
      break;
    }
  }
  cout << ((cur == n) ? "YES" : "NO") << endl;

  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/