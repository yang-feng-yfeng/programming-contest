#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n - 1) { cin >> a[i]; }
  map<int, vector<int>> res;

	set<int> passed;
  rep(i, 0, n - 1) {
	if (passed.find(i) != passed.end()) {
		continue;
	}
	passed.emplace(i);
	vector<int> tmp;
	int next = i;
	while(tmp.size() == 0 || next != tmp[0]) {
		passed.emplace(next);
		tmp.push_back(next);
		next = a[next] - 1;
	}
  }

  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/