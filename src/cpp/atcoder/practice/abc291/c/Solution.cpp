#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n; cin >> n;
  string s;
  cin >> s;
  set<pair<int,int>> passed;
  pair<int, int> cur = make_pair(0, 0);
  passed.emplace(cur);

  rep(i, 0, s.size() - 1) {
    if (s[i] == 'L') {
      cur.first --;
    } else if (s[i] == 'R') {
      cur.first ++;
    } else if (s[i] == 'U') {
      cur.second ++;
    } else if (s[i] == 'D') {
      cur.second --;
    }

    if (passed.find(cur) != passed.end()) {
      cout << "Yes" << endl;
      return -1;
    } else {
      passed.emplace(cur);
    }
   }
   cout << "No" << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/