#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  set<int> replace = {'a' - 'a', 't' - 'a', 'c' - 'a', 'o' - 'a',
                      'd' - 'a', 'e' - 'a', 'r' - 'a'};
  vector<int> countS(27, 0);  // a - z , @
  vector<int> countT(27, 0);  // a - z , @

  rep(i, 0, n - 1) {
    if (s[i] == '@') {
      countS[26]++;
    } else {
      countS[s[i] - 'a']++;
    }

    if (t[i] == '@') {
      countT[26]++;
    } else {
      countT[t[i] - 'a']++;
    }
  }
  int countDiff = 0;
  rep(i, 0, 25) {
    int diff = countS[i] - countT[i];
    if (diff != 0) {
      if (replace.find(i) == replace.end()) {
        cout << "No" << endl;
        return -1;
      }

      if (diff > 0) {
        countT[26] -= diff;
        if (countT[26] < 0) {
          cout << "No" << endl;
          return -1;
        }
      } else {
        countS[26] += diff;
        if (countS[26] < 0) {
          cout << "No" << endl;
          return -1;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll res = solve();
  //   cout << res << endl;
}
/********  Main() Ends Here *************/