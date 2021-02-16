package lcode.prac.array;

import java.util.*;

// https://leetcode.com/problems/combination-sum-iii/
public class Solution216 {
        public List<List<Integer>> combinationSum3(int k, int n) {
            return combinationSum(k, n, new HashSet<>(), new ArrayList<>());
        }

        public List<List<Integer>> combinationSum(int k, int n, Set<Integer> used, List<Integer> loopRes) {
            if (k > 9) {
                return Collections.emptyList();
            }
            if (n > maxSum(k) || n < minSum(k)) {
                return Collections.emptyList();
            }
            if (k == 1) {
                if (!used.contains(n)) {
                    List<Integer> temp = new ArrayList<>(loopRes);
                    temp.add(n);
                    return Collections.singletonList(temp);
                }
                return Collections.emptyList();
            }

            List<List<Integer>> res = new ArrayList<>();
            for (int i = 1; i <= 9; i++ ) {
                if (!used.contains(i)) {
                    used.add(i);
                    loopRes.add(i);
                    List<List<Integer>> tempRes = combinationSum(k - 1, n - i, new HashSet<>(used), loopRes);
                    res.addAll(tempRes);
                    loopRes.remove(loopRes.size()-1);
                }
            }
            return res;
        }
        
        private int maxSum(int k) {
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                sum += ( 10 - i );
            }
            return sum;
        }

        private int minSum(int k) {
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                sum += i;
            }
            return sum;
        }
}
