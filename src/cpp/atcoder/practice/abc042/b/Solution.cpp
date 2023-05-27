#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, 0, n-1) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  rep(i, 0, n-1) {
    cout << s[i];
  }
  cout << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/