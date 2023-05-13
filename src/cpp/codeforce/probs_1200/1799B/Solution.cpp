#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

void op(vector<ll>& a, int first, int second, vector<pair<int, int>>& res) {
  while (a[first] > a[second]) {
    a[first] =
        ceil(static_cast<double>(a[first]) / static_cast<double>(a[second]));
    res.push_back(make_pair(first, second));
  }
  if (a[first] < a[second]) {
    op(a, second, first, res);
  }
}

ll solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  bool isAllEquals = true;
  bool containsOne = false;
  int ref = 0;
  rep(i, 0, n - 1) {
    cin >> a[i];
    if (i != 0) {
      if (a[i] != a[i - 1]) {
        isAllEquals = false;
      }
    }
    if (a[i] == 1) {
      containsOne = true;
    }
    if (a[i] < a[ref]) {
      ref = i;
    }
  }

  if (isAllEquals) {
    cout << "0" << endl;
    return 0;
  }

  if (containsOne) {
    cout << "-1" << endl;
    return -1;
  }

  int cur = 0;
  vector<pair<int, int>> res;

  for (int i = 0; i < n; i++) {
    if (a[i] > a[ref]){
      op(a, i, ref, res);
    } 
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > a[ref]){
      op(a, i, ref, res);
    } 
  }

  cout << res.size() << endl;
  for (auto & r : res) {
    cout << r.first + 1 << " " << r.second + 1 << endl;
  }
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