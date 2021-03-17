package codejam.y2020.r1b.a;
// Remove package line for submit

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int X = in.nextInt();
            int Y = in.nextInt();

            int unsignedX = X > 0 ? X : -X;
            int unsignedY = Y > 0 ? Y : -Y;

            List<Integer> steps = new ArrayList<>();
            boolean ok = validate(unsignedX, unsignedY, steps);
            System.out.println("Case #" + (i+1) + ": " + (ok ? fillResult(steps, X>0, Y>0) :"IMPOSSIBLE"));
        }
        in.close();
    }

    private static String fillResult(List<Integer> steps, boolean isPositiveX, boolean isPositiveY) {
        StringBuilder sb = new StringBuilder();
        for (Integer step : steps) {
            if (step == 1 || step == -1) {
                sb.append( (isPositiveX? 1*step : -1*step) > 0 ? "E": "W" );
            } else {
                sb.append( (isPositiveY? 1*step : -1*step) > 0 ? "N": "S" );
            }
        }
        return sb.toString();
    }

    private static boolean validate(int x, int y, List<Integer> steps) {
        if (x == 0 && y == 0) {
            return true;
        }
        if (x == 1 && y == 0) {
            steps.add(1);
            return true;
        }
        if ( x == 0 && y == 1 ) {
            steps.add(2);
            return true;
        }

        if ( (x % 2 + y % 2) == 1 ) {
            if (x % 2 == 1) {
                steps.add(-1); // W
                if (validate((x+1)/2, y/2, steps)) {
                    return true;
                } else {
                    steps.remove(steps.size() - 1);
                    steps.add(1); // E
                    return validate((x - 1) / 2, y / 2, steps);
                }
            } else {
                steps.add(-2); // S
                if (validate(x/2, (y+1)/2, steps)) {
                    return true;
                } else {
                    steps.remove(steps.size() - 1);
                    steps.add(2); // N
                    return validate(x/ 2, (y-1) / 2, steps);
                }
            }
        } else {
            return false;
        }
    }
}
