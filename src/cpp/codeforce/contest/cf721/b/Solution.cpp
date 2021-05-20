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

string solve(int n, string s) {
	// if even , bob alawys win
	int cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		if (s[i] == '0') {
			cnt ++;
		}
	}
	return (cnt == 1 || cnt % 2 == 0) ? "BOB" : "ALICE";
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i ++) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		string res = solve(n, s);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/