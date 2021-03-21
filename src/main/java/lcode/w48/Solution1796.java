package lcode.w48;

public class Solution1796 {
    public int secondHighest(String s) {

        char[] sa = s.toCharArray();
        int first = -1;
        int second = -1;

        for (char c : sa) {
            if (c >= '0' && c <= '9') {
                int i = (int) (c - '0');
                if (i > first) {
                    second = first;
                    first  = i;
                } else if ( i == first) {
                    continue;
                } else if ( i > second) {
                    second = i;
                } else if ( i == second) {
                    continue;
                }
            }
        }
        return second;
    }
}
