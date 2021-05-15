package codejam.y2021.r1c.a;
// Remove package line for submit

import java.util.Scanner;

class Solution {

//    public static String findNextRoaring(long y) {
////        if (y < 10) {
////            return Integer.toString(12);
////        }
//        String ystr = Long.toString(y);
//        long top = (long) Math.pow(10, (double) ystr.length() / 2);
//        long min = Long.MAX_VALUE;
//        for (int i =1 ; i < top ; i++) {
//            long value = i;
//            long rem = i;
//            int d = Long.toString(i).length();
//            int rep = 0;
//            while (value <= y || rep < 1) {
//                if (Long.toString(rem+1).length() > d) {
//                    d += 1;
//                }
//                value = value * (long)(Math.pow(10, d)) + rem+1;
//                rem++;
//                if (value < 0) {
//                    value = Long.MAX_VALUE;
//                }
//                rep ++;
//            }
//            min = Math.min(min, value);
//        }
//        return Long.toString(min);
//    }

    public static long findNextRoaring(long y) {
        String ystr = Long.toString(y);
        int maxDigit = (ystr.length()+1) / 2;
        long min = Long.MAX_VALUE;
        for (int i = 1; i <= maxDigit; i++) {
            String first = ystr.substring(0, i);
            long firstV = Long.parseLong(first);
            long value;
            long localMin = Long.MAX_VALUE;
            while (firstV < Math.pow(10, i)) {
                long cur = firstV;
                value = cur;
                int rep = 0;
                int curDigits = i;
                while (value <= y || rep < 1) {
                    cur += 1;
                    if (Long.toString(cur ).length() > curDigits) {
                        curDigits++;
                    }
                    value = value * (long) Math.pow(10, curDigits) + cur;
                    rep ++;
                }
                if (value > localMin) {
                    break;
                } else {
                    localMin = value;
                    firstV ++;
                }
            }
            if (Long.toString(localMin).length() > ystr.length()) {
                value = (long) Math.pow(10, i-1);
                long cur = value;
                int rep = 0;
                int curDigits = i;
                while (value <= y || rep <= 1) {
                    cur += 1;
                    if (Long.toString(cur ).length() > curDigits) {
                        curDigits++;
                    }
                    value = value * (long) Math.pow(10, curDigits) + cur;
                    rep ++;
                }
                localMin = Math.min(localMin, value);
            }
            min = Math.min(localMin, min);
        }
        return min;
    }

//    public static long findNext(long y, String ystr, int digits) {
//        String sub = ystr.substring(0, digits);
//        long subl = (long) Math.pow(10, digits - 1) == 0.0 ? 1 : (long) Math.pow(10, digits - 1) ;
//        long value = subl;
//        long min = Long.MAX_VALUE;
//        int rep = 0;
//        while (subl < Math.pow(10, sub.length())) {
//            long rem = subl;
//            value = rem;
//            int d = digits;
//            while (value <= y || rep < 2) {
//                if (Long.toString(rem+1).length() > d) {
//                    d += 1;
//                }
//                value = value * (long)(Math.pow(10, d)) + rem+1;
//                rem++;
//                if (value < 0) {
//                    value = Long.MAX_VALUE;
//                }
//                rep ++;
//            }
//            min = Math.min(min, value);
//            subl++;
//        }
//        return min;
//    }

//    public static boolean isRoaring(long y) {
//        String ystr = Long.toString(y);
//        boolean isRoar = false;
//        for (int i = 1; i <= ystr.length()/2; i++) {
//            int s = 0;
//            int e = s + i;
//            int currlen = i;
//            while (e < ystr.length()) {
//                String cur = ystr.substring(s, currlen);
//                long curV = Long.parseLong(cur);
//                long nextV = curV + 1;
//                String next = Long.toString(nextV);
//                if (!next.equals(ystr.substring(e, next.length()))) {
//                    break;
//                }
//                s = e;
//                currlen = next.length();
//                e = s + currlen;
//            }
//            if (e == ystr.length()) {
//                return true;
//            }
//        }
//        return false;
//    }

//    public static long findNextRoaring(long y) {
//        long i = y + 1 ;
//        while (i < Math.pow(10, 6)) {
//            if (isRoaring(i)) {
//                return i;
//            }
//        }
//        return -1;
//    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            long l = in.nextLong();
            long res = findNextRoaring(l);
            System.out.println("Case #" + (t+1) + ": " + res);
        }
        in.close();
    }
}
