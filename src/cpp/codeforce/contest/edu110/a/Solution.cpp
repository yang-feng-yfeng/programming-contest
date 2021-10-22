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
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		vector<int> skills(4);
		vector<int> copy(4);

		for (int i = 0; i < 4; i++) {
			cin >> skills[i];
			copy[i] = skills[i];
		}
		
		sort(copy.rbegin(), copy.rend());

		if ((skills[0] == copy[0] && skills[1] == copy[1]) || 
			(skills[0] == copy[1] && skills[1] == copy[0]) || 
			(skills[0] == copy[2] && skills[1] == copy[3]) || 
			(skills[0] == copy[3] && skills[1] == copy[2])) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}

	}
}
/********  Main() Ends Here *************/