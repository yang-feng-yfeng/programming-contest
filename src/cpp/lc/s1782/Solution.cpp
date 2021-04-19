#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        unordered_map<int, unordered_map<int, int>> m;
        vector<int> sig(n);
        
        for (auto & e : edges) {
            int e1 = e[0];
            int e2 = e[1];
            
            sig[e1 - 1] ++;
            sig[e2 - 1] ++;
            
            m[e1-1][e2-1]++;
        }
        vector<int> copy(sig);
        
        sort(copy.begin(), copy.end());
        
        vector<int> res;
        for (int i = 0 ; i< queries.size() ; i++) {
            int ans;
            int f = 0, l = copy.size() - 1;
            for(; f < l; ) {
                if(copy[l] - copy[f] > queries[i]) {
                    ans += l - f;
                    l--;
                } else {
                    f++;
                }
            }
            for (auto [a, me] : m) {
                for (auto [b, mek]: me) {
                    if (sig[a-1] + sig[b-1] > queries[i] && sig[a-1] + sig[b-1] - mek <= queries[i]) {
                        ans --;
                    }
                }
            }            
            res.push_back(ans);
        }
        return res;
    }
};