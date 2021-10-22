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
	string s ,t;
	cin >> s >> t;
	int n = s.size();
	int f = -1, k = -1;
	for (int i = 0; i < n ; i++) {
		if (s[i] != t[i]) {
			if (f == -1) {
				f = i;
			} else if ( k == -1 && i == f + 1) {
				k = i;
			} 
		}
	}
	if (f >= 0 && k >= 0){
		char tmp = s[f];
		s[f] = s[k];
		s[k] = tmp;
	}
	cout << (s == t ? "Yes": "No") << endl;
	return 0;
}
/********  Main() Ends Here *************/