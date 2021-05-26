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

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> res;
	for (int i = 0; i < N; i++ ) {
		if (s[i] == '1' || s[i] == '0') {
			continue;
		}
		if (s[i] == '4') {
			res.push_back(3);
			res.push_back(2);
			res.push_back(2);
		}
		else if (s[i] == '6') {
			res.push_back(3);
			res.push_back(5);
		}
		else if (s[i] == '8') {
			res.push_back(7);
			res.push_back(2);
			res.push_back(2);
			res.push_back(2);
		}
		else if (s[i] == '9') {
			res.push_back(3);
			res.push_back(3);
			res.push_back(7);
			res.push_back(2);
		}
		else {
			// cerr << "s: i" << i << " : " << s[i]<<endl;
			res.push_back(s[i] - '0');
		}
	}
	sort(res.rbegin(), res.rend());
	string resstr = "";
	for (int i = 0; i < res.size(); i++) {
		resstr += to_string(res[i]);
	}
	cout << resstr << endl;
}
/********  Main() Ends Here *************/