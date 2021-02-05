package lcode.prac.math;

// https://leetcode.com/problems/reverse-integer/
class Solution7 {
    public int reverse(int x) {
        StringBuilder result = new StringBuilder();
        if (x < 0) {
            x = -x;
            result.append('-');
        }
        
        while (x != 0) {
            int mod = x % 10;
            x = x / 10;
            result.append(mod);
        }
        
        int res;
        try {
           res = Integer.parseInt(result.toString());
        }
        catch (NumberFormatException e)
        {
           res = 0;
        }
        return res;
    }
}