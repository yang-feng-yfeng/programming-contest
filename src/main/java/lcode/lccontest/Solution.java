package lcode.lccontest;

import java.util.*;

public class Solution {
    public int makeStringSorted(String s) {
        long mod = 1000000007;

        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        long res = 0;
        long[] mem = new long[3000];

        for (int i = 0; i < s.length(); i++ ) {
            char cur = s.charAt(i);

            long divider = 1;
            int smaller = countSmaller(count, cur);

            for (int j = 0; j < 26; j++) {
                if (j < (cur- 'a')) {
                    divider *= calA(count[j], mem);
                }
            }

            for (int j = 0; j < 26; j++) {
                if (j < (cur- 'a')) {
                    res += calA(smaller, mem) * count[j] / divider ;
                }
            }
            count[cur]--;
        }

        return (int) res;
    }

    public int nbSmaller(char c) {
        return c - 'a';
    }

    public int countSmaller(int[] count, char c) {
        int res = 0;
        for (int i = 0; i < (c - 'a'); i++) {
            res += count[i];
        }
        return res;
    }

    public long calA ( int i, long[] mem/*, int mod*/) {
        if (i == 1) {
            mem[i] = 1;
            return 1;
        }
        if (mem[i] != 0) {
            return mem[i];
        }
        // % mod
        long res = calA(i - 1, mem) * i;
        mem[i] = res;
        return res;
    }

}
