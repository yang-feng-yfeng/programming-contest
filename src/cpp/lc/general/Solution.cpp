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




vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
using ll = long long;
const int mod = 1000000007;

vector<int> waysToFillArray(vector<vector<int>>& queries) {
    int combi[10013][10013];
    combi[1][1] = 1;

    for (int i = 2; i < 10013; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                combi[i][j] = 1;
                continue;
            }
            combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % mod;
        }
    } 

    vector<int> result(queries.size(), 1);
    for (int q = 0; q < queries.size(); q++) {
        auto & query = queries[q];
        int n = query[0];
        int prod = query[1];

        // divide
        int pmCnt[primes.size()];
        while (prod > 1) {
            for (int i = 0; i < primes.size(); i++) {
                int p = primes[i];
                while (prod % p == 0) {
                    pmCnt[i]++;
                }
            }
        }
        if (prod > 1) {
            result[q] = n;
        } 
        for (int i = 0; i < primes.size(); i++) {
            int r = pmCnt[i];
            result[q] *= combi[n - 1 + r][r] % mod;
        }
    }
    return result;
}

 int minDistance(string word1, string word2) {
    int a = word1.size();
    int b = word2.size();
    int dp[a+1][b+1];
    dp[0][0] = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (j == 0) {
                dp[i][j] = i;
                cout << "dp[" << i << "][" << j << "]: " <<  dp[i][j] << endl;
                continue;
            } 
            if (i == 0) {
                dp[i][j] = j; 
                cout << "dp[" << i << "][" << j << "]: " <<  dp[i][j] << endl;
                continue;
            }
            int minR = 1001;
            if (word1[i-1] == word2[j-1]) {
                minR = min(minR, dp[i-1][j-1]);
            }
            minR = min(minR, dp[i][j-1] + 1);
            minR = min(minR, dp[i-1][j] + 1);
            dp[i][j] = minR;
            cout << "dp[" << i << "][" << j << "]: " <<  dp[i][j] << endl;
        }
    }
    return dp[a][b];
}

int bfs(vector<vector<int>>& mt, vector<vector<bool>>& checked, int i, int j, vector<int> & dir) {
    int count = 0;
    if (!checked[i][j] && mt[i][j] == 1) {
        checked[i][j] = true;
        count++;
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k+1];
            if (ni >=0 && ni < mt.size() && nj >=0 && nj < mt[0].size())
                count += bfs(mt, checked, ni, nj, dir);
        }
    }
    return count; 
}

int solve(vector<vector<int>>& mt) {
    vector<int> dir{-1, 0, 1, 0, -1};
    int n = mt.size();
    int m = mt[0].size();

    vector<vector<bool>> checked(n, vector<bool>(m));
    int maxSize = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxSize = max(bfs(mt, checked, i, j, dir), maxSize);
        }
    }
    return maxSize;
}

bool isCovering(vector<int> & acount, vector<int> & bcount) {
    for (int i = 0; i < 26; i++) {
        if (acount[i] < bcount[i]) {
            return false;
        }
    }
    return true;
}

int solve(string a, string b) {
    vector<int> bcount(26);
    for (int i = 0; i < b.size(); i++) {
        bcount[b[i] - 'a']++;
    }
    int n = a.size();
    int maxSize = -1;

    vector<int> dp(n , -1);
    vector<int> acount(26);
    for (int i = 0; i < n; i++) {
        acount[a[i] - 'a']++;
        if (isCovering(acount, bcount)) {
            dp[0] = i+1;
        }
    }
    if (dp[0] == -1) 
        return -1;
    for (int i = 1; i < n; i++) {
        int rem = i-1;
        acount[a[rem] - 'a']--;
        if (isCovering(acount, bcount)) {
            dp[i] = dp[i-1] - 1;
        } else {
            // find next a[rem] - 'a'
            int jstart = dp[i-1] + i;
            for (int j = 0 ; j + jstart < n; j++) {
                acount[a[j + jstart]- 'a']++;
                if (a[j + jstart] == a[rem]) {
                    dp[i] = dp[i-1] + j;
                }
            }
        }
    }
}

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