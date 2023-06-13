#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int h, w;
  cin >> h >> w;
  vector<vector<char>> c(h+1, vector<char>(w+1));
  rep(i, 1, h) {
    rep(j, 1, w) {
      cin >> c[i][j];
    }
  }
  rep(i, 1, h * 2) {
    rep(j, 1, w) {
      cout << c[(i+1)/2][j];
    }
    cout << endl;
  }

	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/