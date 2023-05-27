#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string s;
  cin >> s;
  int leftB = -1, rightB;
  int leftR = -1, rightR;
  int idxK;
  rep(i, 0, 7) {
    if (s[i] == 'B') {
      if (leftB < 0) leftB = i;
      rightB = i;
    } else if (s[i] == 'K') {
      idxK = i;
    } else if (s[i] == 'R') {
      if (leftR < 0) leftR = i;
      rightR = i;
    }
  }
  if ((rightB - leftB) % 2 == 1 && ( leftR < idxK && rightR > idxK)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll res = solve();
  // cout << res << endl;
}
/********  Main() Ends Here *************/