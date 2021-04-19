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
const ll mod = 1000000007;

class Solution {
public:
    ll powmod(int i, int pow) {
        ll res = 1;
        ll a = i;
        while (pow > 0) {
            if (pow & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            pow >>= 1;
        }
        return res;
    }

    ll inv(int i) {
        return powmod(i, mod - 2);
    }

    int makeStringSorted(string s) {
        vector<ll> amod(3000);
        vector<ll> invmod(3000);

        amod[0] = 1;
        invmod[0] = 1;
        for (int i = 1; i < 3000; i++) {
            amod[i] = i * amod[i-1] % mod;
            invmod[i] = inv(amod[i]);
        }

        vector<int> count(26);
        for (char c: s) {
            count[c - 'a'] ++;
        }
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];

            for (int k = 0; k < 26 ; k++) {
                if (k < (cur -'a') && count[k] != 0)  {
                    int c = count[k];
                    ll div = 1;
                    for (int j = 0; j < 26; j++) {
                        //cout << "invmod[count[j]]: " << invmod[count[j]] << endl;
                        div = div * invmod[count[j]] % mod;
                    }
                    res = (res + amod[s.length() - 1 - i] * c % mod * div ) % mod;
                }
            }
            count[cur - 'a']--;
        }
        return res;
    }
};

int main()
{
	// Empty main for compile
    Solution solution;
    string test = "cba";
    cout<< test << ": " << solution.makeStringSorted(test) << endl;
    test = "aabaa";
    cout<< test << ": " << solution.makeStringSorted(test) << endl;
    test = "cdbea";
    cout<< test << ": " << solution.makeStringSorted(test) << endl;
};