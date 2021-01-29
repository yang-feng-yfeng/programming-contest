// https://leetcode.com/contest/biweekly-contest-44/problems/find-the-highest-altitude/
class Solution {
    public int largestAltitude(int[] gain) {
        int max = 0;
        int current = 0;
        for (int i = 0; i < gain.length; i++) {
            current += gain[i];
            if (current > max) {
                max = current;
            }
        }
        return max;
    }
}