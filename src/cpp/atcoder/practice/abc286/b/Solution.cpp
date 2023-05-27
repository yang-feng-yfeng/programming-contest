#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n; cin >> n;
  string s; cin >> s;
  vector<int> a;
  rep(i, 0, n-2) {
    if (s[i] == 'n' && s[i+1] == 'a') {
      a.push_back(i+1);
      
    }
  }
  for(int i = a.size() -1; i >= 0; i--) {
    s.insert(a[i] + s.begin(), 'y');
  }

  cout << s << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/