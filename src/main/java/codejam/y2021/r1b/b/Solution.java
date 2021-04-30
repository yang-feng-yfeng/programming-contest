package codejam.y2021.r1b.b;
// Remove package line for submit

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            int[] input = new int[N + 1];
            int A = in.nextInt();
            int B = in.nextInt();
            for (int i = 1; i < N + 1; i++) {
                input[i] = in.nextInt();
            }

            boolean isPossible = isPossible(input, A, B);
            int res = 0;
            if (isPossible) {
                res = solve(input, A, B, new HashMap<>());
            }
            System.out.println("Case #" + (t+1) + ": " + (isPossible ? res : "IMPOSSIBLE"));
        }
        in.close();
    }

    public static boolean isPossible(int[] input, int a, int b) {
        int gcd = gcd(a, b);
        int mod = -1;
        for (int i = 0; i < input.length; i++) {
            int in = input[i];
            if (in != 0) {
                int curMod = i % gcd;
                if (mod == -1) {
                    mod = curMod;
                } else {
                    if (curMod != mod ){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public static int findMax(int[] input) {
        for (int i = input.length - 1; i >= 0; i--) {
            if (input[i] != 0) {
                return i;
            }
        }
        return -1;
    }

    public static int solve(int[] input, int a, int b, Map<String, Integer> mem) {
        int gcd = gcd(a, b);
        int start = findMax(input);
        int[] backup = Arrays.copyOf(input, input.length);

        start += Math.min(a,b);
        int[] product = new int[500];

        while (start < 500) {
            product[start] ++;

            while (true) {
                for (int i = 0; i < backup.length; i++) {
                    if (backup[i] != 0 && product[i] !=0) {
                        int toSub = Math.min(backup[i], product[i]);
                        backup[i] -= toSub;
                        product[i] -= toSub;
                    }
                }
                int biggerProd = findMax(product);
                int biggerInput = findMax(backup);
                if (biggerInput == -1) {
                    return start;
                }
                if (biggerProd < biggerInput) {
                    break;
                } else {
                    product[biggerProd] --;
                    if (biggerProd - a >= 0)
                        product[biggerProd - a] ++;
                    if (biggerProd - b >= 0)
                        product[biggerProd - b] ++;
                }
            }
            backup = Arrays.copyOf(input, input.length);
            product = new int[500];
            start+=gcd;
        }
        throw new IllegalStateException("cannot resolve");



//        try {
//            String inputStr = toStr(input);
//            if (mem.containsKey(inputStr)) {
//                return mem.get(inputStr);
//            }
//            int cnt = 0;
//            int sum = 0;
//            for (int i = 0; i < input.length; i++) {
//                if (input[i] != 0) {
//                    cnt += input[i];
//                    sum += i + 1;
//                }
//            }
//            if (cnt == 1) {
//                mem.put(inputStr, sum);
//                return sum;
//            }
//
//
//            int first = 0;
//            while (input[first] == 0) {
//                first++;
//            }
//            if (cnt == 2) {
//                if (input[sum - 1] != 2) {
//                    int second = first + 1;
//                    while (input[second] == 0) {
//                        second++;
//                    }
//                    int curDiff = second - first;
//                    int gcd = gcd(a, b);
//                    if (curDiff % gcd != 0) {
//                        return Integer.MAX_VALUE;
//                    }
//                }
//            }
//            int diff = Math.abs(a - b);
//            int res = -1;
//            if (input[first + diff] != 0) {
//                input[first]--;
//                input[first + diff]--;
//                input[first + Math.max(a, b)]++;
//                res = solve(input, a, b, mem);
//                input[first]++;
//                input[first + diff]++;
//                input[first + Math.max(a, b)]--;
//            } else {
//                input[first]--;
//                input[first + a]++;
//                res = solve(input, a, b, mem);
//                input[first + a] --;
//                input[first + b] ++;
//                res = Math.min(res, solve(input, a, b, mem));
//                input[first + b] --;
//                input[first] ++;
//            }
//            mem.put(inputStr, res);
//            return res;
//        } catch (ArrayIndexOutOfBoundsException e) {
//            return Integer.MAX_VALUE;
//        }
    }

    public static int gcd(int a, int b) {
        a = a % b;
        if (a == 0) {
            return b;
        }
        return gcd(b, a);
    }
}
