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
#define rep(i, l, r) for (ll i = l; i <= r; i++)
vector<int> ept{0};

pair<ll, ll> opt(pair<ll, ll> cv, bool c2v) {
	if (cv.first % 2 == 0) {
		if (c2v) {
			return make_pair(cv.first / 2, cv.second + cv.first / 2);
		} else {
			return make_pair(cv.first + cv.second / 2, cv.second / 2);
		}
	}
	return make_pair(0, 0);
}

vector<int>& dfs(pair<ll, ll> cv, ll targ, vector<int>& res, set<ll>& passed) {
	if (cv.first == 0 || passed.find(cv.first) != passed.end()) {
		return ept;
	}
	if (cv.first == targ) {
		return res;
	}
	if (cv.first != 0) {
		passed.insert(cv.first);
		res.push_back(1);
		auto l = dfs(opt(cv, true), targ, res, passed);
		if (l[0] != 0) {
			return res;
		}
		res.pop_back();
		res.push_back(2);
		auto r = dfs(opt(cv, false), targ, res, passed);
		if (r[0] != 0) {
			return res;
		}
		res.pop_back();
	}
	return ept;
}

void solve() {
	int k, x;
	cin >> k >> x;
	vector<int> res;
	set<ll> passed;
	res = dfs(make_pair(pow(2, k), pow(2, k)), x, res, passed);
	cout << res.size() << endl;
	if (res.size() > 0) {
		rep(i, 0, res.size() -1) {
			cout << res[i] << " ";
		}
	} 
	
	cout << endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long k,x,kk; cin>>k>>x; kk=1ll<<k;
        if (!x||x==kk*2) {cout<<"-1\n"; continue;}
        long long y=kk*2-x;
        vector<int> ans; ans.clear();
        while(x!=kk){
            if (x>y) ans.push_back(2),x-=y,y*=2;
            else ans.push_back(1),y-=x,x*=2;
        }
        cout<<ans.size()<<"\n";
        while(!ans.empty()) cout<<ans.back()<<' ',ans.pop_back();
        cout<<"\n";
    }
    return 0;
}


/********** Main()  function *******/
// int main()
// {
// 	ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
// 	int T;
// 	cin >> T;
// 	for (int t = 0; t < T ; t++) {
// 		solve();
// 	}
// }
/********  Main() Ends Here *************/