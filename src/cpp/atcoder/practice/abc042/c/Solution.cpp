#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

bool ok(int n, set<int> & d) {
  while (n > 0 && d.find(n % 10) == d.end()) {
    n= n/10;
  }
  return n==0;
}


ll solve() { 
  int n, k;
  cin >> n >> k;
  set<int> a;
  rep(i, 0, k-1) {
    int tmp;
    cin >> tmp;
    a.emplace(tmp);
  }

  rep(i, n, 10*n) {
    if (ok(i, a)) {
      cout << i << endl;
      break;
    } 
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