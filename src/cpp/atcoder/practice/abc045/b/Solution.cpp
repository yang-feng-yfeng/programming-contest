#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() { 
  string sa,sb,sc;
  cin >> sa >> sb >> sc;
  int ia = 0, ib = 0, ic = 0;
  int na = sa.size(), nb = sb.size(), nc = sc.size();
  char next = 'a';
  char res;
  while (ia <= na && ib <= nb && ic <= nc) {
    if (next == 'a') {
      if (ia == na) {
        res = 'A';
        break;
      }
      next = sa[ia++];
    } else if (next == 'b') {
      if (ib == nb) {
        res = 'B';
        break;
      }
      next = sb[ib++];
    } else if (next == 'c') {
      if (ic == nc) {
        res = 'C';
        break;
      }
      next = sc[ic++];
    }
    // cout << "next: " << next << endl;
  }
  cout << res << endl;
	return 0 ; 
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/