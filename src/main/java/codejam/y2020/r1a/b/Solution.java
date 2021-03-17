package codejam.y2020.r1a.b;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            List<int[]> paths = new ArrayList<>();
            int sum = 0;
            int[] current = new int[] {1, 1};
            sum += 1;
            paths.add(current);

            if (N < 100) {
                int first = 2, second = 2;
                while (sum < N) {
                    sum += calc(first, second);
                    paths.add(new int[]{first, second});
                    first++;
                }
                if (sum != N) {
                    int[] val = paths.remove(paths.size()-1);
                    sum -= calc(val[0], val[1]);
                    first = val[0] - 1;
                    second = 1;
                    while (sum < N) {
                        sum += calc(first, second);
                        paths.add(new int[]{first, second});
                        first++;
                    }
                }
            } else {
                int newN = N - 30;
                String bs = Integer.toBinaryString(newN); // 32 bits
                //System.out.println(bs);
                for (int i1 = 1 ; i1 < bs.length(); i1++) {
                    // start with the 3rd line
                    int nbLine = i1 + 1;
                    if (bs.charAt(bs.length() - i1 - 1) == '1') {
                        int[] last = paths.get(paths.size() - 1);
                        if (last[1] == 1) {
                            // start down left until bs.length() - i1
                            for (int i2 = last[0] + 1; i2 < nbLine; i2++) {
                                sum += 1;
                                paths.add(new int[] {i2, 1});
                            }
                            // left to right
                            for (int i3 = 1; i3 <= nbLine; i3++) {
                                paths.add(new int[] {nbLine, i3});
                            }
                            sum += (int) Math.pow(2.0, (nbLine-1));
                        } else {
                            // start down left until bs.length() - i1
                            for (int i2 = last[0] + 1; i2 < nbLine; i2++) {
                                sum += 1;
                                paths.add(new int[] {i2, i2});
                            }
                            // right to left
                            for (int i3 = nbLine; i3 >= 1; i3--) {
                                paths.add(new int[] {nbLine, i3});
                            }
                            sum += (int) Math.pow(2.0, (nbLine-1));
                        }
                    }
                }
                int[] last = paths.get(paths.size() - 1);
                int oneAdd = 1;
                while (sum < N) {
                    sum += 1;
                    if (last[1] == 1) {
                        paths.add(new int[]{last[0] + oneAdd, 1});
                        oneAdd++;
                    } else {
                        paths.add(new int[]{last[0] + oneAdd, last[0] + oneAdd});
                        oneAdd++;
                    }

                }
            }
            System.out.println("Case #" + (i+1) + ": ");
            for (int[] path : paths) {
                System.out.println(path[0] + " " + path[1]);
            }
        }
        in.close();
    }

    private static int calc(int i, int j) {
        if (j == 1) {
            return 1;
        } else if (j == 2) {
            return i - 1;
        }
        throw new IllegalStateException("Failed.");
    }

}
