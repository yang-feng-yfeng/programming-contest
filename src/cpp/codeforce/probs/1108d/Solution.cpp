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

int colorToNum(char c) {
	if (c == 'R') {
		return 1;
	} else if (c == 'B') {
		return 2;
	}
	return 4;
}

int solve(int n, string & s) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {
			cnt ++;
			if (i < n-1) {
				int color = 0;
				color |= colorToNum(s[i-1]);
				color |= colorToNum(s[i+1]);
				int rest = 7 - color;
				if (rest & 1) {
					s[i] = 'R';
				} else if (rest & 2) {
					s[i] = 'B';
				} else {
					s[i] = 'G';
				}
				// cout << "s: " <<  s << endl;
			} else {
				int color = 0;
				color |= colorToNum(s[i-1]);
				int rest = 7 - color;
				if (rest & 1) {
					s[i] = 'R';
				} else if (rest & 2) {
					s[i] = 'B';
				} else {
					s[i] = 'G';
				}
			}
		}
	}
	cout << cnt << endl;
	cout << s << endl;
	return cnt;
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	int res = solve(N, s);
	
}
/********  Main() Ends Here *************/