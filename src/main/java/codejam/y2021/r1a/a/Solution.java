package codejam.y2021.r1a.a;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            String[] strArr = new String[N];
            for (int n = 0; n < N; n++) {
                strArr[n] = in.next();
            }
            // greedy
            int res = 0;
            for (int i = 1; i < N; i++) {
                String prev = strArr[i - 1];
                int prevLen = prev.length();
                String curr = strArr[i];
                int currLen = curr.length();

                if (prevLen < currLen) {
                    continue;
                }
                else {
//                    long prevV = Long.parseLong(prev);
//                    long currV = Long.parseLong(curr);

                    if (prevLen == currLen) {
                        if (smaller(prev, curr) ) {
                            continue;
                        } else {
                            curr = curr + "0";
                            res += 1;
                            strArr[i] = curr;
                            continue;
                        }
                    } else {
                        // prevLen > currLen
                        int diff = prevLen - currLen;
                        StringBuilder sb1 = new StringBuilder();
                        sb1.append(curr);
                        for (int i1 = 0; i1 < diff; i1++) {
                            sb1.append("0");
                        }
                        String withZeroStr = sb1.toString();
//                        long withZero = Long.parseLong(withZeroStr);
                        if (smaller(prev, withZeroStr) ) {
                            res += diff;
                            strArr[i] = withZeroStr;
                            continue;
                        }
                        StringBuilder sb2 = new StringBuilder();
                        sb2.append(curr);
                        for (int i1 = 0; i1 < diff; i1++) {
                            sb2.append("9");
                        }
                        String withNineStr = sb2.toString();
//                        long withNine = Long.parseLong(withNineStr);
                        if (smaller(prev, withNineStr)) {
                            // next bigger should be prevV + 1
//                            long newCurrent = Long.parseLong(prev) + 1;
//                            String newCurStr = Long.toString(newCurrent);
//                            char lastDigit = (char)(prev.charAt(prevLen - 1) + 1);
                            String newCurStr = addOne(prev, prevLen -1);

//                            if (newCurStr.startsWith(curr)) {
                            res += diff;
                            strArr[i] = newCurStr;
//                            } else {
//                                sb1.append("0");
//                                res += diff + 1;
//                                strArr[i] = sb1.toString();
//                            }
                        } else {
                            sb1.append("0");
                            res += diff + 1;
                            strArr[i] = sb1.toString();
                        }
                    }
                }
            }
            System.out.println("Case #" + (t+1) + ": " + res);
        }
        in.close();
    }

    public static boolean smaller(String a, String b) {
        // assuming they have same length
        for (int idx = 0; idx < a.length(); idx++) {
            int diff = a.charAt(idx) - b.charAt(idx);
            if (diff < 0) {
                return true;
            } else if (diff > 0) {
                return false;
            }
        }
        return false;
    }

    public static String addOne(String a, int index) {
        char last = a.charAt(index);
        if (last == '9') {
            String str = addOne(a, index - 1);
            return str.substring(0, index) + '0' + a.substring(index + 1);
        }
        return a.substring(0, index) + (char)(last + 1);
    }
}
