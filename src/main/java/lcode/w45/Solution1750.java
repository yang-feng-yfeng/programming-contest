package lcode.w45;

//https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
public class Solution1750 {
    public int minimumLength(String s) {
        int firstIndex = 0;
        int lastIndex = s.length() -1;
        char[] cArray = s.toCharArray();
        // Move
        while (firstIndex < lastIndex) {
            if (cArray[firstIndex] != cArray[lastIndex]) {
                return lastIndex - firstIndex + 1;
            } else {
                // Move first
                while (firstIndex < lastIndex && cArray[firstIndex] == cArray[firstIndex+1]) {
                    firstIndex++;
                }
                firstIndex++;
                // Move last
                while (firstIndex < lastIndex && cArray[lastIndex] == cArray[lastIndex-1]) {
                    lastIndex--;
                }
                lastIndex--;
                //System.out.print("f" + firstIndex + " l" + lastIndex + " ");
            }
        }
        if (firstIndex == lastIndex) {
            return 1;
        }
        return 0;
    }
}
