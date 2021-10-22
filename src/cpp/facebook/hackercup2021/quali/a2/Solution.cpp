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

void printMat(vector<vector<int>> & mat) {
	for (int i = 0; i < 26; i++) {
		cout << (char) ('A' + i) << "  ";
	}
	cout << endl;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			// if (j == 6) {
				// cout << (char) ('A' + i) << " ";
				cout << mat[i][j] << ((mat[i][j] == -1 || mat[i][j] > 9 )? " " : "  ");

			// }
		}
		cout << endl;
	}
}


int solve() {
	string s;
	cin >> s;
	// iterate over 26 characters, calculate every possibilities
	int res = 1e8;
	int cur = 0;
	int n = s.size();

	vector<vector<int>> mat(26, vector<int>(26, -1));
	vector<vector<int>> dir(26);
	int k;
	cin >> k;
	for (int i = 0; i < k ; i ++) {
		string map;
		cin >> map;
		dir[map[0] - 'A'].emplace_back(map[1] - 'A');
	}

	for (int start = 0; start < 26; start++) {
		mat[start][start] = 0;
		queue<int> qq;
		queue<int> tq;
		qq.emplace(start);
		int cur = 1;
		set<int> seen;
		while (!qq.empty()) {
			int next = qq.front();
			seen.insert(next);
			qq.pop();
			for (int n : dir[next]) {
				if (seen.find(n) == seen.end()) {
					mat[start][n] = cur;
					tq.push(n);
				}
			}
			if (qq.empty()) {
				queue<int> tmp = qq;
				qq = tq;
				tq = tmp;
				// cout << "qq size: " << qq.size() << endl;
				// cout << "tq size: " << tq.size() << endl;
				cur++;
			} 
		}
	}
	
	string cp = s;
	sort(cp.begin(), cp.end());
	cout << cp.size() << " : " << cp << endl;
	printMat(mat);
	

	for (int i = 0; i < 26; i++) {
		cur = 0;
		char target = 'A' + i;
		// cout << "target: " << target << endl;sz
		for (int k = 0; k < n; k++) {
			if (s[k] == target) {
				continue;
			}
			if (mat[s[k] - 'A'][i] == -1) {
				cur = 1e8;
				break;
			} else {
				cur += mat[s[k] - 'A'][i];
			}
		}
		cout << "cur : " <<  (char)('A' + i) << " : " << cur << endl;
		res = min(cur, res);
	}
	return res == 1e8 ? -1 : res;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/