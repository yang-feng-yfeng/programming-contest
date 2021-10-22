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
#include <unordered_set>

using namespace std;
using ll = long long;

int solve() {
	return 0;
}

void bfs(int start, int end, vector<pair<int, int>> roads) {
	unordered_set<int> visited;
	
}

/********** Main()  function *******/
int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<pair<int, int>> roads(N-1);


	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		roads[i] = make_pair(a, b);
	}
	vector<pair<int, int>> questions(Q);
	for (int i = 0; i < Q; i++) {
		int c, d;
		cin >> c >> d;
		questions[i] = make_pair(c, d);
	}

	vector<vector<int>> mat(N, vector<int>(N));

}
/********  Main() Ends Here *************/