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
unordered_map<char, int> keyMap;

/********** Main()  function *******/
int main()
{
	string x;
	cin >> x;
	for (int i = 0; i < 26; i++) {
		keyMap[x[i]] = i; 
	}


	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	sort(s.begin(), s.end(), [ ](const string& lhs, const string& rhs) {
		for (int i = 0; i < min(lhs.size(), rhs.size()); i++) {
			if (lhs[i] != rhs[i]) {
				return keyMap[lhs[i]] < keyMap[rhs[i]];
			}
		}
		return lhs.size() < rhs.size();
	});

	for (int i = 0; i < n; i++) cout << s[i] << endl;
	return 0;
}
/********  Main() Ends Here *************/