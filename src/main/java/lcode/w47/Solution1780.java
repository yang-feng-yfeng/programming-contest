package lcode.w47;

// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
public class Solution1780 {

    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n = n / 3;
        }
        return true;
    }

}
