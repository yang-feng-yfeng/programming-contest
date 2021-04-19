package codejam.y2021.quali.c;
// Remove package line for submit

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            int C = in.nextInt();

            int min = N-1;
            int max = N * (N + 1) / 2 - 1;

            String res;
            if (C > max || C < min) {
                res = "IMPOSSIBLE";
            } else {
                boolean[] used = calculate(C, N);
                int[] result = generate(used, N);
                res = Arrays.stream(result).boxed().map(Object::toString).collect(Collectors.joining(" "));
            }

            System.out.println("Case #" + (i+1) + ": " + res);
        }
        in.close();
    }

    private static boolean[] calculate(int target, int N) {
        int index = N;
        target -= (N - 1);
        boolean[] used = new boolean[N + 1];
        while (index >= 0 && target >= (index - 1)) {
            target -= (index - 1);
            used[index--] = true;
        }
        if (target != 0) {
            used[target + 1] = true;
        }
        return used;
    }

    private static int[] generate(boolean[] used, int N) {
        int[] t = new int[N];
        for (int j = 0; j < N; j++) {
            t[j] = j + 1;
        }
        for (int i = N ; i >= 2; i--) {
            // reverse from the reserve side, start with used.length - 1
            if (used[i]) { // i = 4, need to swith 4 with 1
                int first = findIndex(t, 0, N);
                int second = findIndex(t, 0, N - i + 1);
                reverse(t, second, first);
            }

        }
        return t;
    }

    public static void reverse(int[] arr, int from, int to) {
        if (from > to) {
            int tmp = to;
            to = from;
            from = tmp;
        }
        if (from == to) {
            // do nothing
        } else {
            while (to > from) {
                swap(arr, from++, to--);
            }
        }
    }

    public static void swap(int[] arr, int a, int b) {
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }

    public static int findIndex(int[] arr, int from, int value){
        for (int i = from; i < arr.length; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

}
