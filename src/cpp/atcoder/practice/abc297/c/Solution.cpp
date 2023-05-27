#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h-1) {
    cin >> s[i];
    
    rep(j, 1, w-1) {
      if (s[i][j] == 'T' && s[i][j-1] == 'T') {
        s[i][j] = 'C';
        s[i][j-1] = 'P';
      }
    }
    cout << s[i] << endl;
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