package codejam.y2020.quali.c;

import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();
        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            List<int[]> activities = new ArrayList<>();
            char[] ca = new char[N];
            for (int j = 0; j < N ; j++) {
                int first = in.nextInt();
                int second = in.nextInt();
                activities.add(new int[] {first, second, j});
            }
            int lastJEnd = -1;
            int lastCEnd = -1;
            boolean impossible = false;
            activities.sort(Comparator.comparingInt(a -> a[0]));
            for (int[] activity : activities) {
                if (lastCEnd <= activity[0]) {
                    ca[activity[2]] = 'C';
                    lastCEnd = activity[1];
                } else if (lastJEnd <= activity[0]) {
                    ca[activity[2]] = 'J';
                    lastJEnd = activity[1];
                } else {
                    impossible = true;
                    break;
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + (impossible ? "IMPOSSIBLE" : String.valueOf(ca)));
        }
        in.close();
    }
}
