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

string big(int n, int m) {
	string cur = "";
	while (n > 0) {
		if (m - 9 >= 0) {
			cur += "9";
			m -= 9;
		} else {
			cur += to_string(m);
			
			m = 0;
		}
		n --;
	}
	return cur;
}

string small(int n, int m) {
	string cur = "";
	int small = m - (n - 1 ) * 9 ;
	small = small > 0 ? small : 1;
	string b = big(n - 1, m - small);
	reverse(b.begin(), b.end());
	cur = cur + to_string(small) + b;
	return cur;
}

/********** Main()  function *******/
int main()
{
	int n, m;
	cin >> n >> m;
	// int res = solve(n, m);
	string s = "", b = "";
	if (m == 0 && n == 1) {
		s = "0";
		b = "0";
	} else if (m < 1 || m > 9 * n) {
		s = "-1"; 
		b = "-1";
	} else {
		b = big(n, m);
		s = small(n, m);
	}
	cout << s << " " << b << endl;	
}
/********  Main() Ends Here *************/