package codejam.y2020.r1c.a;
// Remove package line for submit

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Map<Character, int[]> direc = new HashMap<>();
        direc.put('S', new int[] {0, -1});
        direc.put('N', new int[] {0, 1});
        direc.put('E', new int[] {1, 0});
        direc.put('W', new int[] {-1, 0});

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int X = in.nextInt();
            int Y = in.nextInt();

            String steps = in.next();
            // Each of step, get new coor, if distance between coor to you is smaller / equals to current step.
            int k;
            int distance = Math.abs(X) + Math.abs(Y);
            for ( k = 0; k < steps.length(); k++) {
                int usedSteps = k + 1;
                int[] direction = direc.get(steps.charAt(k));
                int newX = X + direction[0];
                int newY = Y + direction[1];
                distance = Math.abs(newX) + Math.abs(newY);
                if (distance <= usedSteps) {
                    break;
                } else {
                    X = newX;
                    Y = newY;
                }
            }
            System.out.println("Case #" + (i+1) + ": " + ((k != steps.length()) ? k+1 : "IMPOSSIBLE"));
        }
        in.close();
    }
}
