#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

int calcDiff(string & s, int n) {
  int res = 0;
  rep(i, 0, n/2 - 1) {
    if (s[i] != s[n-1-i]) {
      res++;
    }
  }
  return res;
}

ll solve() { 
  int n; ll a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  ll res = LONG_LONG_MAX;

  rep(i, 0, n-1) {
    string newS = s.substr(i) + s.substr(0, i);
    // cout << "newS: " << newS << endl;
    ll tmp = static_cast<ll>(calcDiff(newS, n)) * b + a * i;
    res = min(res, tmp);
  }

  cout << res << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/