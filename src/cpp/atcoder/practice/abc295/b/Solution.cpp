#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

ll solve() { 
  int r,c;
  cin >> r >> c;
  vector<string> a(r);
  rep(i, 0, r-1) {cin >> a[i];}
  rep(i, 0, r-1) {
    rep(j, 0, c-1) {
      if(a[i][j] >= '1' && a[i][j] <= '9') {
        int k = a[i][j] - '1' + 1;
        cout << "k: " << k << endl;
        rep(x, 0, r-1) {
          rep(y, 0, c-1) {
            if (a[x][y] == '#' &&  (abs(x-i) + abs(y-j)) <= k ) {
              a[x][y] = '.';
              // cout << "c: " << c << " b:" << b << endl;
            }
          }
        }
        a[i][j] = '.';
      }
    }
  }

  rep(i, 0, r-1) {
    cout << a[i] << endl;
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