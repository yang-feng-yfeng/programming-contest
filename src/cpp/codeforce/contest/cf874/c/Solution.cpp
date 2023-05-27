#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> odds;

  rep(i, 0, n - 1) {
    cin >> a[i];
    if (a[i] % 2 == 1) {
      odds.push_back(a[i]);
    }
  }

  if (odds.size() == 0 || odds.size() == n) {
	return 0;
  } 

  sort(a.begin(), a.end());

  if (a[0] % 2 == 0) {
	return -1;
  } else {
	return 0;
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
    cout << ((res == 0) ? "yes" : "no")  << endl;
  }
}
/********  Main() Ends Here *************/