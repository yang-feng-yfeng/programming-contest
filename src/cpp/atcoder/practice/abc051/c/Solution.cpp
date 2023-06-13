#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solveIteration(int sx, int sy, int tx, int ty, string& res) {
  if (tx > sx) {
    rep(i, 1, tx - sx) { res += 'R'; }
  } else {
    rep(i, 1, sx - tx) { res += 'L'; }
  }

  if (ty > sy) {
    rep(i, 1, ty - sy) { res += 'U'; }
  } else {
    rep(i, 1, sy - ty) { res += 'D'; }
  }
  return 0;
}

ll solve() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  string res = "";
  // 1st s->t
  solveIteration(sx, sy, tx, ty, res);
  // 1st t->s
  solveIteration(tx, ty, sx, sy, res);
  // 2nd s->t and t->s
  int nsx = sx, nsy = sy, ntx = tx, nty = ty;
  if (sx <= tx) {
    if (sy <= ty) {
      res += 'D';
      solveIteration(sx, sy - 1, tx + 1, ty, res);
      res += 'L';
      res += 'U';
      solveIteration(tx, ty + 1, sx - 1, sy, res);
      res += 'R';
    } else {
      res += 'U';
      solveIteration(sx, sy + 1, tx, ty + 1, res);
      res += "LD";
      solveIteration(tx, ty - 1, sx - 1, sy, res);
      res += 'R';
    }
  } else {
    if (sy <= ty) {
      res += 'R';
      solveIteration(sx+1, sy, tx, ty+1, res);
      res += "DL";
      solveIteration(tx-1, ty, sx, sy-1, res);
      res += 'U'; 
    } else {
      res += 'U';
      solveIteration(sx, sy+1, tx-1, ty, res);
      res += "RD";
      solveIteration(tx, ty-1, sx+1, sy, res);
      res += 'L';
    }
  }
  //

  cout << res << endl;
  return 0;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
}
/********  Main() Ends Here *************/