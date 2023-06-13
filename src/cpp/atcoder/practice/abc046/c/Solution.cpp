#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  ll a = 1, b = 1;
  ll ta, tb;
  rep(i, 1, n) {
    cin >> ta >> tb;
    if (ta == tb) {
      a = max(a, b);
      b = max(a, b);
    } else {
      if (ta * 1.0 / tb * b < a * 1.0) {
        // b need increase
        if (b % tb != 0) {
          b = (b / tb + 1) * tb;
        }
        int esA = b / tb * ta;
        if (esA < a) {
          if (a % ta != 0) {
            a = (a / ta + 1) * ta;
          }
          b = a / ta * tb;
        } else {
          a = esA;
        }
      } else {
        // a need increase
        if (a % ta != 0) {
          a = (a / ta + 1) * ta;
        }
        int esB = a / ta * tb;
        if (esB < b) {
          if (b % tb != 0) {
            b = (b / tb + 1) * tb;
          }
          a = b / tb * ta;
        } else {
          b = esB;
        }
      }
    }
  }
  cout << a + b << endl;
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/