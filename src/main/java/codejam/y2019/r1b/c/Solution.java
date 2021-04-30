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

    public static int calculate(List<Integer> fl, List<Integer> sl, int start, int end, int k) {
        if (end == start) {
            return fl.get(end) - sl.get(end) <= k ? 1 : 0;
        }

        int fmIdx = 0;
        int flmax = -1;

        int smIdx = 0;
        int slmax = -1;
        for (int i = start; i < end; i++) {
            if (flmax < fl.get(i)) {
                fmIdx = i;
                flmax = fl.get(i);
            }
            if (slmax < sl.get(i)) {
                smIdx = i;
                slmax = sl.get(i);
            }
        }
        int result = 0;
        if (Math.abs(flmax - slmax) > k ) {
            // reomve big
            if (flmax > slmax) {
                result += calculate(fl, sl, start, fmIdx, k) ;
                result += calculate(fl, sl, fmIdx + 1, end, k);
            } else {

            }
        }

        return result;
    }


}
