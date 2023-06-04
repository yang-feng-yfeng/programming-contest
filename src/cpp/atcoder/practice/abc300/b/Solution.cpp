#include <bits/stdc++.h>

#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int h, w;
  cin >> h >> w;
  vector<int> ha(w), wa(h), hb(w), wb(h);
  rep(i, 0, h - 1) {
    string tmp;
    cin >> tmp;
    rep(j, 0, w - 1) {
      if (tmp[j] == '#') {
        ha[j]++;
        wa[i]++;
      }
    }
  }
  // cout << "FIrst " << endl;
  rep(i, 0, h - 1) {
    string tmp;
    cin >> tmp;
    rep(j, 0, w - 1) {
      if (tmp[j] == '#') {
        hb[j]++;
        wb[i]++;
      }
    }
  }
  sort(ha.begin(), ha.end());
  sort(hb.begin(), hb.end());
  sort(wa.begin(), wa.end());
  sort(wb.begin(), wb.end());

  rep(i, 0, w - 1) {
    if (ha[i] != hb[i]) {
      cout << "No" << endl;
      return -1;
    }
  }
  rep(i, 0, h - 1) {
    if (wa[i] != wb[i]) {
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