#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> latin(26, -1);
  string str;
  cin >> str;
  rep(i, 0, n - 1) {
    int c = str[i] - 'a';
    if (latin[c] == -1) {
      latin[c] = i;
    } else {
      if ((i - latin[c]) % 2 != 0) {
        cout << "No" << endl;
        return -1;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    // cout << res << endl;
  }
}
/********  Main() Ends Here *************/