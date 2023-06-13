#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
const ll mod = 1e9+7;

ll solve() { 
  int n ;
  cin >> n;
  map<int, int> cnt;
  rep(i, 2, n) {
    int cur = i;
    int k = 2;
    while (k * k <= cur) {
      while (cur % k == 0) {
        cur = cur / k;
        // cout << "curL " << cur << endl;
        cnt[k]++;
      }
      k++;
      //  cout << "curL2 " << cur << endl;
    }
    if (cur > 1) {
      cnt[cur]++;
    }
  }
  ll res = 1;
  for(auto p: cnt) {
    res = res * (p.second + 1) % mod;
  }
  cout << res << endl;
	return res; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/