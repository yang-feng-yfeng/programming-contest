package codejam.y2019.r1b.c;
// Remove package line for submit

import java.util.*;



class Solution {

    static final class Pair<U, V>
    {
        public final U first;       // the first field of a pair
        public final V second;      // the second field of a pair

        // Constructs a new pair with specified values
        private Pair(U first, V second)
        {
            this.first = first;
            this.second = second;
        }

        @Override
        // Checks specified object is "equal to" the current object or not
        public boolean equals(Object o)
        {
            if (this == o) {
                return true;
            }

            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair<?, ?> pair = (Pair<?, ?>) o;

            // call `equals()` method of the underlying objects
            if (!first.equals(pair.first)) {
                return false;
            }
            return second.equals(pair.second);
        }

        @Override
        // Computes hash code for an object to support hash tables
        public int hashCode()
        {
            // use hash codes of the underlying objects
            return 31 * first.hashCode() + second.hashCode();
        }

        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }

        // Factory method for creating a typed Pair immutable instance
        public static <U, V> Pair <U, V> of(U a, V b)
        {
            // calls private constructor
            return new Pair<>(a, b);
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            int K = in.nextInt();

            List<Integer> gList = new ArrayList<>();
            List<Integer> dList = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                gList.add(in.nextInt());
            }
            for (int i = 0; i < N; i++) {
                dList.add(in.nextInt());
            }

//            int count = countPair(gList, dList, K);

            System.out.println("Case #" + (t+1) + ": ");
        }
        in.close();
    }

    private static int[] countPair(List<Integer> gList, List<Integer> dList, int k, int from, int to) {
        if (to - from == 1 ) {
//            List<Pair<Integer, Integer>> l = new ArrayList<>();
            if (Math.abs(gList.get(from) - dList.get(from)) <= k) {
                return new int[] {from, 1, from, 1}; // from, from count, to, to count
            }
//            return l;
        }

        int mid = (gList.size() + dList.size()) / 2;
//        List<Pair<Integer, Integer>> firstPairs = countPair(gList, dList, k, 0, mid+1);
//        List<Pair<Integer, Integer>> secondPairs = countPair(gList, dList, k, mid + 1, gList.size());

        // merge
//        firstPairs.sort((a,b) -> -a.second + b.second);
//        secondPairs.sort((a, b) -> a.second - b.second);
//
//        if (firstPairs.get(0).second + 1 == secondPairs.get(0).first) {
//
//        }
        return null;
    }

    private static int[] countContinuesPair(List<Integer> gList, List<Integer> dList, int k, int from, int to) {
        if (to - from == 1 ) {
            if (Math.abs(gList.get(from) - dList.get(from)) <= k) {
                return new int[] {1, 0};
            }
            return new int[]{0, 0};
        }
        return null;
    }




}
