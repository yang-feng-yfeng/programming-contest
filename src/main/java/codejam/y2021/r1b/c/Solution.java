package codejam.y2021.r1b.c;
// Remove package line for submit

import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.concurrent.BlockingDeque;
import java.util.stream.Collectors;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
//        try {
//            Thread.sleep(10000);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }

        int T = in.nextInt();
        int N = in.nextInt();
        int B = in.nextInt();
        long P = in.nextLong();
        System.err.println("N, B, P : " + N + " " + B + " " + P);


        for (int t = 0; t < T; t++) {
            int[] buildings = new int[N];
            int[][] values = new int[N][B];

            for (int i = 0; i < N * B; i++) {
                int v = in.nextInt();
                int max = -1;
                int maxIdx = -1;
                int scdMax = -1;
                int scdMaxIdx = -1;
                int thirdMax = -1;
                int thirdMaxIdx = -1;
                int fourthMax = -1;
                int fourthMaxIdx = -1;
                int min = B+10;
                int minIdx = -1;
                for (int j = 0; j < N; j++) {
                    if (buildings[j] > max && buildings[j] < B) {
                        max = buildings[j];
                        maxIdx = j;
                    } else if (buildings[j] > scdMax && buildings[j] <= (B-2) && buildings[j] < max) {
                        scdMax = buildings[j];
                        scdMaxIdx = j;
                    } else if (buildings[j] > thirdMax && buildings[j] <= (B-2) && buildings[j] < scdMax) {
                        thirdMax = buildings[j];
                        thirdMaxIdx = j;
                    } else if (buildings[j] > fourthMax && buildings[j] <= (B-2) && buildings[j] < thirdMax) {
                        fourthMax = buildings[j];
                        fourthMaxIdx = j;
                    }
                    if (buildings[j] < min) {
                        min = buildings[j];
                        minIdx = j;
                    }
                }

                if (v > 8 && max == (B - 1)) {
                    System.out.println(maxIdx + 1);
                    buildings[maxIdx] ++;
                    values[maxIdx][max] = v;
                } else if (v > 3 && max == (B - 2)) {
                    System.out.println(maxIdx + 1);
                    buildings[maxIdx] ++;
                    values[maxIdx][max] = v;
                } else if (max < B - 2) {
                    System.out.println(maxIdx + 1);
                    buildings[maxIdx] ++;
                    values[maxIdx][max] = v;
                } else {
                    if (max >= B-2 && scdMaxIdx != -1) {
                        System.out.println(scdMaxIdx + 1);
                        buildings[scdMaxIdx] ++;
                        values[scdMaxIdx][scdMax] = v;
                    } else {
                        if (scdMax >= B-2 && thirdMax != -1) {
                            System.out.println(thirdMaxIdx + 1);
                            buildings[thirdMaxIdx] ++;
                            values[thirdMaxIdx][thirdMax] = v;
                        } else {
                            if (thirdMax >= B-2 && fourthMax != -1) {
                                System.out.println(fourthMaxIdx + 1);
                                buildings[fourthMaxIdx ] ++;
                                values[fourthMaxIdx][fourthMax] = v;
                            } else {
                                System.out.println(minIdx + 1);
                                buildings[minIdx] ++;
                                values[minIdx][buildings[minIdx]-1] = v;
                            }
                        }

                    }
                }

            }
            System.err.println(Arrays.stream(values).map(ints -> {
                StringBuilder sb = new StringBuilder();
                for (int i = ints.length - 1; i >= 0; i--) {
                    //System.err.println("ints[i]: " + ints[i]);
                    sb.append(ints[i]);
                }
                return sb.toString();
            }).collect(Collectors.joining(",")));
        }
        int res = in.nextInt();
        if (res == -1) {
            throw new IllegalStateException("Wrong answer!");
        }
        in.close();
    }
}
