package codejam.y2021.r1a.b;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            long[] primeCount = new long[N];
            List<Integer> primes = new ArrayList<>();
            for (int n = 0; n < N; n++) {
                int p = in.nextInt();
                long count = in.nextLong();
                primeCount[n] = count;
                primes.add(p);
            }

            long sum = 0;
            for (int i = 0; i < primes.size(); i++) {
                sum += primes.get(i) * primeCount[i];
            }

            // backtracking
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < primeCount.length; j++) {
                sb.append(primeCount[j]).append(" ");
            }
            HashMap<String, Long> mem = new HashMap<>();
            long val = bt(sum, primes, sb.toString(), sum, 1, mem);

            long result = mem.values().stream().mapToLong(i -> i).max().getAsLong();
            System.out.println("Case #" + (t+1) + ": " + result);
        }
        in.close();
    }

    public static long bt(long sum, List<Integer> primes, String sumUsed, long currentSum, long currentProd, Map<String, Long> mem) {
        if (currentSum == currentProd) {
            mem.put(sumUsed, currentProd);
            return currentProd;
        }
        if (mem.containsKey(sumUsed)) {
            return mem.get(sumUsed);
        }

        int[] currCount = toCount(primes, sumUsed);
        long max = 0;
        for (int i = primes.size() - 1; i >= 0; i--) {
            if (currCount[i] - 1 >= 0) {
                int take = primes.get(i);
                currCount[i] -= 1;
                currentSum -= take;
                currentProd *= take;
                StringBuilder sb = toCountStr(currCount);
                if (currentProd >= sum || currentProd > currentSum) {
                    mem.put(sb.toString(), 0L);
                    currCount[i] += 1;
                } else {
                    long res = bt(sum, primes, sb.toString(), currentSum, currentProd, mem);
                    max = Math.max(max, res);
                    currCount[i] += 1;
                }
                currentSum += take;
                currentProd /= take;
            }
        }
        mem.put(sumUsed, max);
        return max;
    }

    private static int[] toCount(List<Integer> primes, String sumUsed) {
        int[] currCount = new int[primes.size()];
        String[] split = sumUsed.split(" ");
        for (int i = 0; i < currCount.length; i++) {
            currCount[i] = Integer.parseInt(split[i]);
        }
        return currCount;
    }

    private static StringBuilder toCountStr(int[] currCount) {
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < currCount.length; j++) {
            sb.append(currCount[j]).append(" ");
        }
        return sb;
    }

}
