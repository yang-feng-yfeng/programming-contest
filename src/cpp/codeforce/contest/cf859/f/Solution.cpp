#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

string dir[] = {"DR", "DL", "UR", "UL"};
pair<int, int> coords[] = {
    make_pair(1, 1),
    make_pair(1, -1),
    make_pair(-1, 1),
    make_pair(-1, -1),
};

ll solve() {
  int n, m, i1, i2, j1, j2;
  cin >> n >> m >> i1 >> j1 >> i2 >> j2;
  string d;
  cin >> d;

  set<tuple<int, int, int>> passed;
  int dirIdx;
  for (int i = 0; i < 4; i++) {
    if (dir[i] == d) {
      dirIdx = i;
      break;
    }
  }

  i1--;
  i2--;
  j1--;
  j2--;
  int res = 0;
  while (true) {
    if (i1 == i2 && j1 == j2) {
      return res;
    }
    // cout << " i1: " << i1 << " j1: " << j1 << " dir: " << dir[dirIdx] << endl;
    auto passCoords = make_tuple(i1, j1, dirIdx);
    if (passed.find(passCoords) != passed.end()) {
    //   cout << " i1: " << i1 << " j1: " << j1 << endl;
      return -1;
    }
    passed.insert(passCoords);

    // find next;
    auto [iMove, jMove] = coords[dirIdx];
    i1 += iMove;
    j1 += jMove;

    if (i1 < 0) {
      if (j1 < 0) {
        i1 = -i1;
        j1 = -j1;
        dirIdx = 0;  // "DR"
      } else if (j1 >= m) {
        i1 = -i1;
        j1 = m - 2;
        dirIdx = 1;  // "DL"
      } else {
        i1 = -i1;
        if (jMove > 0) {
          dirIdx = 0;  // "DR"
        } else {
          dirIdx = 1;  // "DL"
        }
      }
      res++;
    } else if (i1 >= n) {
      if (j1 < 0) {
        i1 = n - 2;
        j1 = -j1;
        dirIdx = 2;  // UR
      } else if (j1 >= m) {
        i1 = n - 2;
        j1 = m - 2;
        dirIdx = 3;  // UL
      } else {
        i1 = n - 2;
        if (jMove > 0) {
          dirIdx = 2;  // UR
        } else {
          dirIdx = 3;  // UL
        }
      }
      res++;
      // cout << " i1: " << i1 << " j1: " << j1 << " dir: " << dir[dirIdx] <<
      // endl;

    } else if (j1 < 0) {
      j1 = 1;
      if (iMove > 0) {
        dirIdx = 0;  // DR
      } else {
        dirIdx = 2;  // UR
      }
      res++;
      //  cout << " i1: " << i1 << " j1: " << j1 << " dir: " << dir[dirIdx] <<
      //  endl;
    } else if (j1 >= m) {
      j1 = m - 2;
      if (iMove > 0) {
        dirIdx = 1;  // DL
      } else {
        dirIdx = 3;  // UL
      }
      res++;
      //  cout << " i1: " << i1 << " j1: " << j1 << " dir: " << dir[dirIdx] <<
      //  endl;
    }
  }
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