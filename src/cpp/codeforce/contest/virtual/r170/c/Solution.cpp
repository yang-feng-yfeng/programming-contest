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


int solve(string a, string b) {
	int n = a.size();
	int m = b.size();
	int maxL = -1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m - i; j++) {
			string rest = b.substr(i, m - j - i);
			//cout << "rest1: " << rest << endl;
			if (a.find(rest) != string::npos) {
				if ((int)rest.size() > maxL) {
					//cout << "rest: " << rest << endl;
					maxL = rest.size();
				}
				// maxL = max(maxL, (int)rest.size()); 
			}
		}
	}
	return (n - maxL) + m - maxL;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		string a,b ;
		cin >> a >> b;
		int res = solve(a, b);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/