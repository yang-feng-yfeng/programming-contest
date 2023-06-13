#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int dup = 0;
  rep(i, 1, n-1) {
    if (a[i] == a[i-1]) {
      dup ++;
    }
  }
  
	return n - (dup % 2 == 0 ? dup : (dup + 1)); 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << solve() << endl;
}
/********  Main() Ends Here *************/