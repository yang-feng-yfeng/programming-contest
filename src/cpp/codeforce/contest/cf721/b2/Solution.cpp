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

bool isPalin(int n , string s) {
	for (int i = 0 ; i < n/2 ; i++) {
		if (s[i] != s[n-1 -i]) {
			return false;
		}
	}
	return true;
}

string solve(int n, string s) {

	// 2 cnt 
	// cnt 1 : number of 0
	// cnt 2 : how many steps to be palin

	int cnt1 = 0;
	int cnt2 = 0;
	if (n % 2  == 0) {
		for (int i = 0; i < n/2 ; i++) {
			if (s[i] != s[n-1-i]) {
				cnt1 ++;
				cnt2 ++;
			} else {
				if (s[i] == '0') {
					cnt1 +=2 ;
				}
			}
		}
	} else {
		for (int i = 0; i < n/2 ; i++) {
			if (s[i] != s[n-1-i]) {
				cnt1 ++;
				cnt2 ++;
			} else {
				if (s[i] == '0') {
					cnt1 +=2 ;
				}
			}
		}
		if (s[n/2] == '0') {
			cnt1++;
		}
	}
	
	// 1 step to palin, alice fill the palin. if rest 0 is even. Alice win. If no rest 0. alice could R. Alice win
	// 2 step to palin, alice reverse, bob fill, alice fill the palin. Alice win. 
	// 3 or more steps to palin, alice reverse, If 1 step left to palin, case rest 0 is even: Alice fill, case rest 0 is odd, Alice reverse and wait
	if (cnt2 == 0) {
		return (cnt1 == 1 || cnt1 % 2 == 0) ? "BOB" : "ALICE";
	}
	if (cnt2 == 1) {
		if (cnt1 == 1) {
			return "ALICE";
		} 
		if (cnt1 == 2) {
			return "DRAW";
		} 
		return "ALICE";
	}
	if (cnt2 == 2) {
		if (cnt1 == 2) {
			return "ALICE";
		} 
		if (cnt1 == 3) {
			return "ALICE";
		}
		return "ALICE";
	}
	return "ALICE";
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i ++) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		string res = solve(n, s);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/