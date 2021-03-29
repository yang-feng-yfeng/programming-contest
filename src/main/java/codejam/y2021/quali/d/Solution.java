package codejam.y2021.quali.d;
// Remove package line for submit

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Collectors;

class Solution {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt(), n = in.nextInt(), q = in.nextInt();

        for (int i = 0; i < T; i++) {
            System.out.println("1 2 3");
//            System.err.println("1 2 3");
            String medium = in.next();
            int val = Integer.parseInt(medium);
//            System.err.println("val " + val);
            List<Integer> res = new ArrayList<>();

            if (val == 2) {
                res.add(1);
                res.add(2);
                res.add(3);
            } else if (val == 1) {
                res.add(2);
                res.add(1);
                res.add(3);
            } else if (val == 3) {
                res.add(1);
                res.add(3);
                res.add(2);
            }

            for (int k = 4; k <= n; k++) {
//                System.err.println("Current: " + res.stream().map(Objects::toString).collect(Collectors.joining(" ")));
                int index = binarySearch(res, -1, res.size(), k, in);
                res.add(index, k);

            }


            String result = res.stream().map(Objects::toString).collect(Collectors.joining(" "));

            System.out.println(result);
            int ret = in.nextInt();
            if (ret == 1) {
                // Do nothing
//                System.err.println("Case # Success!");
            }
//            System.err.println("Case #" + (i+1) + ": " + ret);
        }
        in.close();
    }

    public static int binarySearch(List<Integer> list, int left, int right, int k,  Scanner in) {
        if (left == right) {
            return left;
        }
        if (right - left == 1) {
            return left + 1;
        }
        int leftMid = left + (right - left) / 3;
        leftMid = Math.max(leftMid, 0);
        int rightMid = leftMid + (right - left ) / 3;
        rightMid = leftMid == rightMid ? rightMid + 1: rightMid;
        Integer leftMidV = list.get(leftMid);
        Integer rightMidV = list.get(rightMid);
        System.out.println(leftMidV + " " + rightMidV + " " + k);
//        System.err.println(leftMidV + " " + rightMidV + " " + k);
        String medium = in.next();
        int val = Integer.parseInt(medium);
//        System.err.println("val " + val);
        if (val == leftMidV) {
            return binarySearch(list, left, leftMid, k, in);
        } else if (val == k) {
            return binarySearch(list, leftMid, rightMid, k, in);
        } else if (val == rightMidV) {
            return binarySearch(list, rightMid, right, k, in);
        } else {
            throw new IllegalStateException("Cannot reach this state.");
        }
    }
}
