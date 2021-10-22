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
	for (int t = 0; t < T; t++) {
		int n,k;
		string a,b;
		cin >> n >> k;
		cin >> a >> b;

		vector<int> acnt(26);
		vector<int> bcnt(26);
		for (int i = 0; i < n; i++) {
			acnt[a[i]-'a']++;
			bcnt[b[i]-'a']++;
		}
		
		bool res = true;
		for (int i = 0; i < 26; i++) {
			if (i == 25) {
				if (acnt[i] - bcnt[i] != 0) {
					res = false;
				}
				break;
			} 
			if ((acnt[i] - bcnt[i]) < 0 || (acnt[i] - bcnt[i]) % k != 0) {
				res = false;
				break;
			} else {
				acnt[i+1] += acnt[i] - bcnt[i];
			}
		}

		cout << (res ? "Yes" : "No") << endl;
	}
	
}
/********  Main() Ends Here *************/