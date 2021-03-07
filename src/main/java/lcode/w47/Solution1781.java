package lcode.w47;

// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/
public class Solution1781 {

    public int beautySum(String s) {
        char[] ca = s.toCharArray();
        int sum = 0;

        for (int i = 0; i < ca.length; i++) {
            int[] counts = new int[26];
            counts[ca[i] - 'a']++;
            for (int j = i + 1; j < ca.length; j++) {
                counts[ca[j] - 'a']++;
                int max = 0;
                int min = 501;

                for (int count : counts) {
                    if (count != 0) {
                        max = Math.max(max, count);
                        min = Math.min(min, count);
                    }
                }
                sum += max - min;
            }
        }
        return sum;
    }
}
