package codejam.y2020.quali.a;
// Remove package line for submit

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int T = in.nextInt();
        in.nextLine();

        for (int i = 0; i < T; i++) {
            int trace = 0, nbRow = 0, nbCol = 0;

            int N = in.nextInt();
            in.nextLine();
            Map<Integer, Set<Integer>> colSet = new HashMap<>();
            for (int k = 0; k < N; k++) {
                Set<Integer> lineSet = new HashSet<>();
                for (int j = 0; j < N; j++) {
                    int current = in.nextInt();
                    Set<Integer> colS = colSet.getOrDefault(j, new HashSet<>());
                    colS.add(current);
                    colSet.put(j, colS);
                    if (k == j) {
                        trace += current;
                    }
                    lineSet.add(current);
                }
                if (lineSet.size() != N)
                    nbRow ++;
            }
            nbCol = (int) colSet.values().stream().filter(s -> s.size() != N).count();
            System.out.println("Case #" + (i+1) + ": " + trace + " " + nbRow + " " + nbCol);
        }
        in.close();
    }
}
