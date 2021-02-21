package lcode.w46;

// https://leetcode.com/problems/longest-nice-substring/
public class Solution1763 {
    public String longestNiceSubstring(String s) {
        String ret = "";
        int maxNice = -1;
        char[] ca = s.toCharArray();

        for (int i = 0 ; i < s.length(); i++) {
            int[] arrayCount = new int[26 * 2];
            for (int j = i; j < s.length(); j++) {
                if (ca[j] >= 'a' && ca[j] <= 'z') {
                    arrayCount[(int)ca[j]-(int)'a'] ++;
                }
                if (ca[j] >= 'A' && ca[j] <= 'Z') {
                    arrayCount[26 + (int)ca[j]-(int)'A'] ++;
                }

                if (isNice(arrayCount)) {
                    int currentSize = j-i + 1;
                    if (currentSize > maxNice) {
                        maxNice = currentSize;
                        ret = s.substring(i, j+1);
                    }
                }
            }
        }
        return ret;
    }

    private boolean isNice(int[] arrayCount) {
        for (int i = 0; i < 26; i++) {
            if ((arrayCount[i] == 0 && arrayCount[i+26] > 0) || (arrayCount[i] > 0  && arrayCount[i+26] == 0)) {
                return false;
            }
        }
        return true;
    }
}
