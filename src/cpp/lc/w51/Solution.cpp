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

string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 1) {
                s[i] = s[i-1] + (int)s[i];
            }
        }
        return s;
    }

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
	sort(rooms.begin(), rooms.end());
	int n = rooms.size();
	int maxMatrix[n+1][n+1];
	unordered_map<int, int> map;
	for (int i = 0; i < n; i ++) {
		map[rooms[i][0]] = i;
		int m = -1;
		for (int j = i + 1; j < n; j++) {
			m = max(m, rooms[j][1]);
			maxMatrix[i][j] = m;
		}
	}

	vector<int> res;
	for (vector<int> & q: queries) {
		int idx = 0;
		int num = q[0];
		int miniSize = q[1];
		int start = map[num];
		int r = -1;
		for (int i = start; i < n; i++) {
			if (maxMatrix[start][i] >= miniSize) {
				r = i;
			}
		}
		int l = -1;
		for (int j = 0, j < start; j++) {
			if (matrix[j][start] >= miniSize) {
				l = j;
			}
		}
		if (r - start >= start - l) {
			res.push_back(l);
		} else {
			res.push_back(r);
		}
	}
	return res;
}


/********** Main()  function *******/
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		string res = "test";
		cout << "Case #" << t <<": " << res << endl;
	}
}
/********  Main() Ends Here *************/