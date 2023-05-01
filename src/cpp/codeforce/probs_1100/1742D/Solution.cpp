#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  unordered_map<int, int> valueToMaxIdx;
  int tmp;
  rep(i, 0, n - 1) {
    cin >> tmp;
    if (valueToMaxIdx.find(tmp) != valueToMaxIdx.end()) {
      valueToMaxIdx[tmp] = max(valueToMaxIdx[tmp], i + 1);
    } else {
      valueToMaxIdx[tmp] = i + 1;
    }
  }

  int res = -1;
  rep(i, 1, 1000) {
    rep(j, 1, 1000) {
      if (valueToMaxIdx.find(i) == valueToMaxIdx.end() ||
          valueToMaxIdx.find(j) == valueToMaxIdx.end()) {
        continue;
      }
      if (__gcd(i, j) == 1) {
        res = max(res, valueToMaxIdx[i] + valueToMaxIdx[j]);
      }
    }
  }
  return res;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/