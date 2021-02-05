package lcode.prac.math;

import java.util.Map;

// https://leetcode.com/problems/roman-to-integer/
public class Solution13 {
    Map<Character, Integer> romeToNum =  Map.of(
            'I', 1,
            'V', 5,
            'X', 10,
            'L', 50,
            'C', 100,
            'D', 500,
            'M', 1000
    );

    public int romanToInt(String s) {

        int sum = 0;
        char[] cArray = s.toCharArray();
        int i = 1;
        for (; i < cArray.length; i++) {
            int first = romeToNum.get(cArray[i-1]);
            int second = romeToNum.get(cArray[i]);
            if (first >= second) {
                sum += first;
            } else {
                sum -= first;
            }
        }
        sum += romeToNum.get(cArray[i-1]);
        return sum;
    }
}
