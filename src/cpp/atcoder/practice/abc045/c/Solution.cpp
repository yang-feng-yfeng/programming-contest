#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  string s;
  cin >> s;
  int n = s.size();

  ll dp[n+1] = {0};

  for (int i = 1; i <= n; i++) {
    string cur = s.substr(0, i);
    ll curNum = stoll(cur);
    int nCur = 1;
    ll twoPow = 1;
    while (nCur < i) {
      string trail = s.substr(nCur, i - nCur);
      dp[i] += dp[nCur] + stoll(trail) * twoPow;
      twoPow *=2;
      nCur++;
    }
    dp[i] += curNum;
  }

  cout << dp[n] << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/