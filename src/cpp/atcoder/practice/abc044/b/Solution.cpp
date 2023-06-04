#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  vector<int> count(26);
  string w;
  cin >> w;
  int n = w.size();
  for(int i=0; i< n; i++) {
    if (w[i] >= 'a' && w[i] <= 'z') {
      count[w[i] - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (count[i] % 2 == 1) {
      cout << "No" << endl;
      return -1;
    }
  }
  cout << "Yes" << endl;
	return 0; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/