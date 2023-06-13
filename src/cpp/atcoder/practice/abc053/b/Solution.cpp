#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string s;
  cin >> s;
  int n = s.size();
  int i = 0, j = n - 1;
  while (i < n) {
    if (s[i] != 'A') {
      i++;
    } else {
      break;
    }
  }
  while (j >= 0) {
    if (s[j] != 'Z') {
      j--;
    } else {
      break;
    }
  }
  cout << j - i + 1 << endl;
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/