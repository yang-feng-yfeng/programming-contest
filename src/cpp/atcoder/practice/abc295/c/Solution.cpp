#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n;
  cin >> n;
  map<int, int> colorCnt;
  rep(i, 0, n-1) {
    int tmp;
    cin >> tmp;
    colorCnt[tmp]++;
  }

  int res = 0;
  for( auto p : colorCnt) {
    res += (p.second / 2);
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