package kickstart.y2020.ra.c;
// Remove package line for submit

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int n = in.nextInt();
            int k = in.nextInt();
            List<Integer> sessions = new ArrayList<>();
            List<Integer> diff = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                int next = in.nextInt();
                sessions.add(next);
                if (j > 0) {
                    diff.add(next - sessions.get(j-1));
                }
            }
            int max = sessions.stream().max(Comparator.naturalOrder()).get();
            diff.sort(Comparator.reverseOrder());

            int res = 0;
            int start = 1;
            int end = max;

            while (start < end) {
                int mid = start / 2 + end / 2;
                int current = calculateK(diff, mid);
                if (current == k) {
                    end = mid;
                } else if (current < k) {
                    end = mid;
                } else if (current > k) {
                    start = mid + 1;
                }
            }
            System.out.println("Case #" + (i+1) + ": " + start);
        }
        in.close();
    }

    private static int calculateK(List<Integer> diffs, int diffTarget) {
        int k = 0;
        for (Integer diff : diffs) {
            k += Math.ceil(diff * 1.0 / diffTarget) - 1;
        }
        return k;
    }

}
