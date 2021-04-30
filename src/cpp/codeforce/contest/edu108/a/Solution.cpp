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

using namespace std;

bool solve(int a, int b, int c) {
	// cout << a <<  " " << b << " " << c << endl;
	if (a > b) {
		int tmp = b;
		b = a;
		a = tmp;
	} 
	double res = b * 1.0 / a;
	// cout << res << endl;
	return (res - 1 ) <= c ;
}

/********** Main()  function *******/
int main()
{
	int T;
	int r, b, d;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> r >> b >> d ;
		bool res = solve(r, b, d);
		cout << (res ? "YES" : "NO" )<< endl;
	}
}
/********  Main() Ends Here *************/