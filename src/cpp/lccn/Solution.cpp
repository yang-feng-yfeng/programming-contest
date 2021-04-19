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

using namespace std;

class Solution {
public:
    int electricCarPlan(vector<vector<int> >& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        vector<vector<int> > dist(n, vector<int>(cnt + 1, INT_MAX));
        dist[start][0] = 0;

        vector<vector<pair<int,int>>> adj(n);
        for (auto& path : paths) {
            // u[e[0]].emplace_back(e[1], e[2]);
            // v[e[1]].push_back({e[0], e[2]});
            
        }
        
        
        
        vector<vector<int>> u;
        vector<vector<int>> v;
        // node become id + charge



        
    }
};