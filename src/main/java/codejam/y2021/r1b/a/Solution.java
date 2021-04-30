package codejam.y2021.r1b.a;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();


        for (int t = 0; t < T; t++) {
            long first = in.nextLong();
            long second = in.nextLong();
            long third = in.nextLong();
            int[] res = tryFit(first, second, third);
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                res = tryFit(first, third, second);
            }
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                res = tryFit(second, first, third);
            }
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                res = tryFit(second, third, first);
            }
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                res = tryFit(third, first, second);
            }
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                res = tryFit(third, second, first);
            }
            if (res[0] < 0 || res[1] < 0 || res[2] < 0 || res[3] < 0) {
                throw new IllegalStateException("wrong answer");
            }
            System.out.println("Case #" + (t+1) + ": " + res[0] + " " + res[1] + " " + res[2] + " " +res[3]);
        }
        in.close();
    }

    public static int[]  tryFit(long hour, long minute, long second) {
        long mod = 1000000000;
        int[] res = new int[] {-1, -1, -1, -1};

        long diff = hour - minute;
        long secondDiff = second - minute;

        for (long a = 0 ; a < 12 ; a++) {
            long n11 = (3600 * mod * a - diff);
            if (n11 % 11 == 0) {
                int[] a1 = getInts(mod, diff, secondDiff, a, n11);
                if (a1 != null) return a1;
            }
            if ((n11 + (mod * 12 * 3600)) % 11 == 0) {
                int[] a1 = getInts(mod, diff, secondDiff, a, n11 + (mod * 12 * 3600));
                if (a1 != null) return a1;
            }
            if ((n11 - (mod * 12 * 3600)) % 11 == 0) {
                int[] a1 = getInts(mod, diff, secondDiff, a, n11 - (mod * 12 * 3600));
                if (a1 != null) return a1;
            }
        }

        return res;
    }

    private static int[] getInts(long mod, long diff, long secondDiff, long a, long n11) {
        long n = n11 / 11;

        long d = n % mod;
        long c = (n - d) / mod;
        long b = c / 60;
        c = c % 60;

        if ( c >= 0 && b >= 0 && b < 60L && d >= 0) {
            if ( (708 * (c * mod + d) - 12 * 60 * b * mod - secondDiff) % (mod * 12 * 3600) == 0) {
                return new int[] {(int) a,(int)b,(int)c,(int)d};
            }
        }
        return null;
    }
}
