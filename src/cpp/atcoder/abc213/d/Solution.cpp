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
using ll = long long;

int dfs(vector<vector<int>> & tree, int cur, set<int> & visited) {
	
	visited.insert(cur);
	cout << cur << " ";
	for (int next: tree[cur]) {
		if (visited.find(next) == visited.end()) {
			dfs(tree, next, visited);
			cout << cur << " ";
		}
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> roads(2 * n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		roads[2 * i] = make_pair(a,b);
		roads[2 * i + 1] = make_pair(b, a);
	}
	sort(roads.begin(), roads.end());
	set<int> visited;

	vector<vector<int>> tree(n + 1);
	// cout << "road size: " << roads.size();
	for (auto road : roads) {
		tree[road.first].push_back(road.second);
	}

	dfs(tree, 1, visited);
	cout << "\n";
}
/********  Main() Ends Here *************/