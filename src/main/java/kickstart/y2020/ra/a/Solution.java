package kickstart.y2020.ra.a;
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
            int a = in.nextInt();
            List<Integer> prices = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                prices.add(in.nextInt());
            }

            prices.sort(Comparator.naturalOrder());
            int sum = 0;
            int count = 0;
            while (sum <= a && count < prices.size()) {
                sum += prices.get(count++);
            }
            System.out.println("Case #" + (i+1) + ": " + (sum > a ? (count - 1) : count));
        }
        in.close();
    }
}
