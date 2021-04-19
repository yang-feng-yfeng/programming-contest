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


template<typename T>
class BIT_opsum {
public:
    T operator() (const T& u, const T& v) const {
        return u + v;
    }
};

template<typename T, typename Accumulate = BIT_opsum<T>>
class BIT {
private:
    vector<T> tree;
    Accumulate op;
    int n;

public:
    BIT(int _n, Accumulate _op = Accumulate{}): n(_n), tree(_n + 1), op(_op) {}

    static int lowbit(int x) {
        return x & (-x);
    }
    
    void update(int x, T value) {
        while (x <= n) {
            tree[x] = op(tree[x], value);
            x += lowbit(x);
        }
    }

    T query(int x) const {
        T ans{};
        while (x) {
            ans = op(ans, tree[x]);
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {

public:
    int reverseInt(int input) { 
        long inputL = input;
        long reversedNum = 0;

        while (inputL > 0) {
            reversedNum = reversedNum * 10 + inputL % 10;
            inputL = inputL / 10;
        }

        if (reversedNum > INT_MAX || reversedNum < INT_MIN) {
            throw new range_error("");
        }
        return reversedNum;
    }

    unordered_map<int, int> intCount(vector<int> & vi) {
        unordered_map<int,int> m;
        for( int i : vi) {
            int c = m[i];
            m[i] = c+1;
        }
        return m;
    }


};
