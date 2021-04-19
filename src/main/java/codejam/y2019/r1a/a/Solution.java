package codejam.y2019.r1a.a;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int r = in.nextInt();
            int c = in.nextInt();

            String res = "";
            List<String> steps = new ArrayList<>();
            if (r + c <= 6) {
                res = "IMPOSSIBLE";
            } else {
                res = "POSSIBLE";
                backtracking(steps, new boolean[r * c], r, c,100,200);
            }
            System.out.println("Case #" + (i+1) + ": " + res);
            if (!steps.isEmpty()) {
                for (String step : steps) {
                    System.out.println(step);
                }
            }
        }
        in.close();
    }

    public static boolean isOk (int prevR, int preC, int curR, int curC) {
        return (preC != curC ) && (prevR != curR) && (prevR - preC != curR - curC) && (prevR + preC != curC + curR);
    }

    public static boolean backtracking(List<String> steps, boolean[] stepSet, int r, int c, int prevR, int prevC) {
        if (steps.size() == r * c) {
            return true;
        } else {
            for (int i = prevR + 1; i <= prevR + r; i++) {
                for (int j = prevC + 2; j <= prevC + 1 + c; j++) {
                    int curR = (i % r == 0) ? r : i % r;
                    int curC = (j % c == 0) ? c : j % c;
                    String step = curR + " " + curC;
                    int currentStep = (curR - 1) * c + curC - 1;
                    if (!stepSet[currentStep]) {
                        if (steps.isEmpty()) {
                            steps.add(step);
                            stepSet[currentStep] = true;
                            if (backtracking(steps, stepSet, r, c, curR, curC)) {
                                return true;
                            }
                            steps.remove(steps.size() - 1);
                            stepSet[currentStep] = false;
                        } else {
                            if (isOk(prevR, prevC, curR, curC)) {
                                steps.add(step);
                                stepSet[currentStep] = true;
                                if (backtracking(steps, stepSet, r, c, curR, curC)){
                                    return true;
                                }
                                steps.remove(steps.size() - 1);
                                stepSet[currentStep] = false;
                            }
                        }
                    }
                }
            }
            return false;
        }
    }
}
