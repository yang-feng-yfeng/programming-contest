#include <bits/stdc++.h>

#include <queue>
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

class Solution {
    
 private:

  int findRootAndCompression(vector<int>& g, int cur) {
    if (cur == g[cur]) {
      return cur;
    }
    int root = findRootAndCompression(g, g[cur]);
    g[cur] = root;
    return root;
  }

  void union_merge(vector<int>& g, vector<int>& num, int a, int b) {
    int aRoot = findRootAndCompression(g, a);
    int bRoot = findRootAndCompression(g, b);
    if (aRoot == bRoot) {
        return;
    }
    if (num[aRoot] < num[bRoot]) {
        swap(aRoot, bRoot);
    }

    g[bRoot] = aRoot;
    num[aRoot] += num[bRoot];
  }

 public:
  bool canTraverseAllPairs(vector<int>& nums) {
    if (nums.size() == 1) {
      return true;
    }
      
      
      
    int n = nums.size();
    vector<int> g(n), num(n ,1); // union-find set
    for (int i = 0; i < n; i++) {
      g[i] = i;
    }
    unordered_map<int, int> have;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == 1) {
            return false;
        }
        for(int d= 2; d * d < x; ++d) {
            if (x % d == 0) {
                if (have.count(d)) {
                    union_merge(g, num, i, have[d]);
                } else {
                    have[d] = i;
                }
                while (x % d == 0) {
                    x /= d;
                }
            }
        }
        if (x > 1) {
            if (have.count(x)) {
                union_merge(g, num, i, have[x]);
            } else {
                have[x] = i;
            }
        }
    }
    return num[findRootAndCompression(g, 0)] == n;

  }
};