package codejam.y2020.r1c.c;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            int D = in.nextInt();
            List<Long> angles = new ArrayList<>();
            Map<Long, Integer> counts = new HashMap<>();

            for (int j = 0; j < N; j++) {
                angles.add(in.nextLong());
            }

            double max = angles.stream().reduce(Long::sum).get() * 1.0 / (D*1.0);
            // pieces < D
            int minCut = D - 1;
            angles.sort(Comparator.naturalOrder());
            for (int k = 1; k < D; k++) {
                int index = 0;
                double partSize = angles.get(index) * 1.0 / k;
                while (index < angles.size() && partSize <= max) {
                    // Use it
                    int nbcut = k - 1;
                    int nbPart = k;
                    int current = 0;
                    while (current < angles.size() && nbPart < D) {
                        if (current != index) {
                            double l = angles.get(current) * 1.0 % partSize;
                            if (l == 0) {
                                long l1 = (long) (angles.get(current) / partSize);
                                nbPart += l1;
                                nbcut += (l1 - 1);
                            }
                        }
                        current ++;
                    }
                    if (nbPart < D) {
                        nbcut += (D - nbPart);
                    } else if (nbPart > D){
                        nbcut -= (nbPart - D - 1) ;
                    }
                    minCut = Math.min(nbcut, minCut);
                    index ++;
                }
            }
            System.out.println("Case #" + (i+1) + ": " + minCut);
        }
        in.close();
    }
}
