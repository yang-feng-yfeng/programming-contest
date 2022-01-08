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

string solve() {
	string x1, x2; 
	int p1, p2;
	cin >> x1 >> p1 >> x2 >> p2;
	int size1 = x1.size() + p1;
	int size2 = x2.size() + p2;

	if (size1 > size2) {
		return ">";
	} else if (size1 < size2) {
		return "<";
	} else {
		int com_size = max(x1.size(), x2.size());
		long num1 = pow(10, com_size - x1.size()) * stoi(x1);
		long num2 = pow(10, com_size - x2.size()) * stoi(x2);
		if (num1 > num2) 
			return ">";
		else if (num1 < num2) 
			return "<";
		else 
			return "=";
	}


}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		string res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/