package codejam.y2020.quali.b;

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        in.nextLine();

        for (int i = 0; i < T; i++) {
            StringBuilder result = new StringBuilder();

            String input = in.next();
            int leftPar = 0;
            char[] ca = input.toCharArray();
            for (char c : ca) {
                int diff = leftPar - (c - '0');
                if (diff == 0) {
                    result.append(c);
                } else if (diff > 0){
                    result.append(")".repeat(diff)).append(c);
                    leftPar -= diff;
                } else {
                    result.append("(".repeat(-diff)).append(c);
                    leftPar -= diff;
                }
            }
            if (leftPar > 0) result.append(")".repeat(leftPar));
            System.out.println("Case #" + (i + 1) + ": " + result.toString());
        }
        in.close();
    }
}
