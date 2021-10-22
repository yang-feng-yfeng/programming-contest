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

int solve() {
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(2*n, vector<char>(m));
	int k  = 2 * n;
	for (int i = 0; i < 2 *n ; i++) {
		for (int j = 0; j < m ; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> win(2 * n, 0);
	auto comp = [&win](int a, int b) {
		return (win[a] == win[b]) ? (a > b) : win[a] < win[b];
	};
	priority_queue<int, vector<int>, decltype(comp)> curOdr(comp);
	priority_queue<int, vector<int>, decltype(comp)> nextOdr(comp);

	while ( --k >= 0) {
		curOdr.push(k);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int cur = curOdr.top();
			curOdr.pop();
			int opp = curOdr.top();
			curOdr.pop();

			char curOut = a[cur][i];
			char oppOut = a[opp][i];

			if (curOut == oppOut) {
				// do nothing
			} else if ( (curOut == 'G' && oppOut == 'C' ) || 
			(curOut == 'C' && oppOut == 'P' ) || 
			(curOut == 'P' && oppOut == 'G' ) ) {
				win[cur]++;
			} else {
				win[opp]++;
			}
			nextOdr.push(cur);
			nextOdr.push(opp);
		}
		while (!nextOdr.empty()) {
			curOdr.push(nextOdr.top());
			nextOdr.pop();
		}
	} 
	
	while (!curOdr.empty()) {
		cout << (curOdr.top() + 1) << endl;
		curOdr.pop();
	}
	return 0;

}
/********  Main() Ends Here *************/