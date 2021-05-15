package codejam.y2021.r1c.c;
// Remove package line for submit

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            int K = in.nextInt();
            int[] sold = new int[N];
            for (int i = 0; i < N; i++) {
                sold[i] = in.nextInt();
            }
            int[] sorted = Arrays.stream(sold).sorted().toArray();

            List<Integer> candidates = new ArrayList<>();

            double max = -1.0;
            long all = K;
            if (K > 30) {
                candidates.add(1);
                for (int i = 0; i < sorted.length - 1; i++) {
                    if (sorted[i+1] - sorted[i] > 1) {
                        candidates.add(sorted[i] + (sorted[i+1] - sorted[i])/ 3);
                        candidates.add(sorted[i] + (sorted[i+1] - sorted[i])/ 3 + 1);
                        candidates.add((sorted[i+1] + sorted[i])/ 2);
                        candidates.add(sorted[i] + 2 * (sorted[i+1] - sorted[i])/ 3);
                        candidates.add(sorted[i] + 2 * (sorted[i+1] - sorted[i])/ 3 + 1);
                    }
                }
                candidates.add(K);
                for (int i = 0; i < candidates.size(); i++) {
                    for (int j = i + 1; j < candidates.size(); j++) {
                        long winPositions = 0;
                        for (int l = 0; l < sorted.length - 1; l++) {
                            winPositions += getWinPositions(sorted, candidates, i, j, l);
                        }
                        int cani = candidates.get(i);
                        int canj = candidates.get(j);
                        if (Math.min(cani, canj) < sorted[0]) {
                            winPositions += Math.min(cani, canj);
                        }
                        if (Math.max(cani, canj) > sorted[sorted.length - 1]) {
                            winPositions += (K - Math.max(cani, canj) + 1);
                        }
                        max = Math.max(max, winPositions * 1.0 / all);
                    }
                }
            } else {
                for (int i = 1; i <= K; i++) {
                    candidates.add(i);
                }
                for (int i = 0; i < candidates.size(); i++) {
                    for (int j = i + 1; j < candidates.size(); j++) {
                        int cani = candidates.get(i);
                        int canj = candidates.get(j);
                        long winPositions = 0;

                        for (int k = 1; k <= K; k++) {
                            boolean counti = true;
                            boolean countj = true;
                            for (int value : sorted) {
                                if (counti && (Math.abs(cani - k) >= Math.abs(value - k))) {
                                    counti = false;
                                }
                                if (countj && (Math.abs(canj - k) >= Math.abs(value-k))) {
                                    countj = false;
                                }
                            }
                            winPositions += (counti || countj) ? 1 : 0;
                        }
                        max = Math.max(max, winPositions * 1.0 / all);
                    }
                }
            }



            System.out.println("Case #" + (t+1) + ": " + max);
        }
        in.close();
    }

    private static long getWinPositions(int[] sorted, List<Integer> candidates, int i, int j, int l) {
        int winPositions = 0;
        int cani = candidates.get(i);
        int canj = candidates.get(j);
        if (sorted[l] < cani && sorted[l +1] > cani) {
           if (sorted[l] < canj && sorted[l +1] > canj) {
               winPositions += Math.abs(cani- canj) + 1;
               winPositions += (Math.min(cani, canj) - sorted[l] - 1) / 2;
               winPositions += (sorted[l +1] - Math.max(cani, canj) -1) / 2;
           } else {
               winPositions += (cani - sorted[l] - 1) / 2;
               winPositions += (sorted[l +1] - cani -1) / 2;
               winPositions += 1;
           }
        } else if (sorted[l] < canj && sorted[l +1] > canj) {
            winPositions += (canj - sorted[l] - 1) / 2;
            winPositions += (sorted[l +1] - canj -1) / 2;
            winPositions += 1;
        }
        return winPositions;
    }

}
