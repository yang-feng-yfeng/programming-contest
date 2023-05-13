#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  int u, v;
  rep(i, 0, m - 1) {
    cin >> u >> v;
    edges.push_back(make_pair(u, v));
    edges.push_back(make_pair(v, u));
  }

  sort(edges.begin(), edges.end());
  int count = 1;
  map<int, int> countmap;
  for (const auto &edge : edges) {
    // cout << "edge: " << edge.first << " " << edge.second << endl;
  }

  rep(i, 1, edges.size() - 1) {
    if (edges[i].first == edges[i - 1].first) {
      count++;
    } else {
      if (countmap.find(count) != countmap.end()) {
        countmap[count]++;
        // cout << "count: " << count << "i: " << i << endl;
      } else {
        countmap.emplace(count, 1);
      }
      count = 1;
    }
  }
  if (countmap.find(count) != countmap.end()) {
    countmap[count]++;
    // cout << "count: " << count << endl;
  } else {
    countmap.emplace(count, 1);
  }

	int x, y;
  if (countmap.size() == 2) {
    // 2 possibility
    // x = 1, y
    int tmp;
    for (const auto &entry : countmap) {
      if (entry.first == 1) {
        tmp = entry.second;
		break;
      }
    }

	if (n - tmp == 1) {
		x = 1;
		y = n -2;
	} else {
		//x = y + 1;
		for (int i = 1; i <= n; i++) {
			if (tmp == i * (i+1)) {
				y = i;
				break;
			}
		}
		x = y+1;
	}
  } else {
    int xy;
    for (const auto &entry : countmap) {
      if (entry.second == 1) {
        x = entry.first;
      }
      if (entry.first == 1) {
        xy = entry.second;
      }
    }
    y  =xy / x;
  }
cout << x << " " << y << endl;
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
    // cout << res << endl;
  }
}
/********  Main() Ends Here *************/