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

ll secondMax(vector<vector<int>> &x, vector<vector<int>> &y, int N) {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<int> xmx = x[N-1];
	vector<int> xmin = x[0];
	vector<int> xsecondmx = x[N-2];
	vector<int> xsecondmin = x[1];

	vector<int> ymx = y[N-1];
	vector<int> ymin = y[0];
	vector<int> ysecondmx = y[N-2];
	vector<int> ysecondmin = y[1];

	ll yfirst = abs(((ll) ymx[0] - ymin[0]));
	ll xfirst = abs(((ll) xmx[0] - xmin[0]));
	ll ysec = max(abs((ll) ymx[0] - ysecondmin[0]), abs((ll) ysecondmx[0] - ymin[0]));
	ll xsec = max(abs((ll) xmx[0] - xsecondmin[0]), abs((ll) xsecondmx[0] - xmin[0]));

	// cout << "yfirst: " << yfirst << " xfirst: " << xfirst << " ysec: " << ysec<< " xsec: " << xsec << endl; 

	if ((ymx[1] == xmx[1] && ymin[1] == xmin[1] ) || (ymx[1] == xmin[1] && ymin[1] == xmx[1])) { 
		return max(ysec, xsec);
	}
	if ( yfirst > xfirst ) {
		return max(ysec, xfirst);
	} else {
		return max(yfirst, xsec);
	}
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> x(N, vector<int>(2)), y(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> x[i][0];
		x[i][1] = i;
		cin >> y[i][0];
		y[i][1] = i;
	}

	cout << secondMax(x, y, N) << endl; 
	
}
/********  Main() Ends Here *************/