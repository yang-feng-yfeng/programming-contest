#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  int sum = 0;
  rep(i, 0, n-1) {
    cin >> x[i];
    x[i] -= a;
    sum += x[i];
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