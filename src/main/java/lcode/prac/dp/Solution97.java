package lcode.prac.dp;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution97 {
    public boolean isInterleave(String s1, String s2, String s3) {
        List<int[]>[] dp = new List[s3.length()];

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        if (s3.length() == 0) {
            return true;
        }

        dp[0] = new ArrayList();
        if (!s1.isEmpty() && s3.charAt(0) == s1.charAt(0)) {
            dp[0].add(new int[] {0, -1});
        }
        if (!s2.isEmpty() && s3.charAt(0) == s2.charAt(0)) {
            dp[0].add(new int[] {-1, 0});
        }


        for (int i = 1 ; i < s3.length(); i++) {
            dp[i] = new ArrayList<>();
            if (!dp[i-1].isEmpty()) {
                List<int[]> pairs = dp[i-1];
                Map<Integer,Integer> newM = new HashMap<>();
                for (int[] pair: pairs) {
                    if (pair[0] < (s1.length() - 1) && s1.charAt(pair[0]+1) == s3.charAt(i)) {
                        newM.put(pair[0]+1, pair[1]);
                    }
                    if (pair[1] < (s2.length() - 1) && s2.charAt(pair[1]+1) == s3.charAt(i)) {
                        newM.put(pair[0], pair[1]+1);
                    }
                }
                for (Map.Entry<Integer, Integer> e : newM.entrySet()) {
                    dp[i].add(new int[] {e.getKey(), e.getValue()});
                }
            } else {
                return false;
            }
        }

        return !dp[s3.length() -1].isEmpty();
    }
}
