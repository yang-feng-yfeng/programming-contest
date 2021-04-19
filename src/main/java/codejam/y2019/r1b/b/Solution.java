package codejam.y2019.r1b.b;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        int W = in.nextInt();

        for (int t = 0; t < T; t++) {
            System.out.println("220");
            long ret2 = in.nextLong();
            long r4 = ret2 / (1L << 55);
            long rest = ret2 % (1L << 55);
            long r5 = rest / (1L << 44);
            rest = rest % (1L << 44);
            long r6 = rest / (1L << 36);

            System.out.println("54");
            long ret1 = in.nextLong();

            long r1 = ret1 / (1L << 54);
            rest = ret1 % (1L << 54);
            long r2 = rest / (1L << 27);
            rest = rest % (1L << 27) - r4 * (1L << 13);
            long r3 = rest / (1L << 18);



            System.out.println(r1 + " " + r2 + " " + r3 + " " + r4 + " " + r5 + " " + r6 );
            int ans = in.nextInt();
            if (ans != 1) {
                return ;
            }
        }
        in.close();
    }
}
