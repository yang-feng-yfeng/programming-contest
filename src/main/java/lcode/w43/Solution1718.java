package lcode.w43;

//https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
public class Solution1718{
    public int[] constructDistancedSequence(int n) {
        int[] res = new int[n * 2 - 1];
        boolean[] used = new boolean[n+1];
        calc(0, res, used, n);
        return res;
    }

    public boolean calc(int index, int[] solution, boolean[] used, int n) {
        if (index > solution.length - 1) {
            return true;
        }
        if (solution[index] != 0) {
            return calc(index+1, solution, used, n);
        } else {
            for ( int i = n; i >= 1; i-- ) {
                if (i == 1) {
                    if (!used[i] && solution[index] == 0) {
                        solution[index] = i;
                        used[i] = true;
                        if (calc(index+1, solution, used, n)) {
                            return true;
                        }
                        else {
                            solution[index] = 0;
                            used[i] = false;
                        }
                    }
                } else {
                    if (!used[i] && solution[index] == 0 && (index+i)<(n*2-1) && solution[index+i] == 0) {
                        solution[index] = i;
                        solution[index+i] = i;
                        used[i] = true;
                        if (calc(index+1, solution, used, n)) {
                            return true;
                        }
                        else {
                            solution[index] = 0;
                            solution[index+i] = 0;
                            used[i] = false;
                        }
                    }
                }


            }
            return false;
        }
    }

}
