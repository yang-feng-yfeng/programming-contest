package codejam.y2020.r1b.b;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();

        for (int i = 0; i < t; i++) {
            // Find the first point inside of the dart
            Random random = new Random();
            int oneB = (int) Math.pow(10, 9);
            int firstX = random.nextInt(2 * oneB) - oneB;
            int firstY = random.nextInt(2 * oneB) - oneB;
            System.out.println(firstX + " " + firstY);
            String state = in.next();
            while (state.equals("MISS")) {
                firstX = random.nextInt(2 * oneB) - oneB;
                firstY = random.nextInt(2 * oneB) - oneB;
                System.out.println(firstX + " " + firstY);
                state = in.next();
            }
            if (state.equals("CENTER")) {
                // Rare
                continue;
            } else {
                // "HIT"
                // Use binary search to find the edge

                // on axe X, fix the Y
                int edgeX1 = binarySearch(firstY, -oneB, firstX, false, false, in);
                int edgeX2 = binarySearch(firstY, firstX, oneB, false, true, in);

                // On axe Y, fix the X
                int edgeY1 = binarySearch(firstX, -oneB, firstY, true, false, in);
                int edgeY2 = binarySearch(firstX, firstY, oneB, true, true, in);

                if ( edgeX1 == -1  || edgeX2 == -1 || edgeY1 == -1 || edgeY2 == -1) {
                    continue;
                }
                System.out.println((edgeX1 + edgeX2)/2 + " " + (edgeY1 + edgeY2)/2);
                if (!in.next().equals("CENTER")) {
                    throw new IllegalStateException("Wrong anwser");
                }
            }
        }
        in.close();
    }

    private static int binarySearch(int fix, int from, int to, boolean isXAxeFixed, boolean increaseDir, Scanner in) {
//        if (from == to) {
//            return from;
//        }
        int mid = from + (to-from)/2;
        if (isXAxeFixed) {
            System.out.println(fix + " " + mid);
        } else {
            System.out.println(mid + " " + fix);
        }
        String state = in.next();
        if (state.equals("HIT")) {
            int nextMid = increaseDir ? mid + 1: mid - 1;
            if (isXAxeFixed) {
                System.out.println(fix + " " + nextMid);
            } else {
                System.out.println(nextMid + " " + fix);
            }
            state = in.next();
            if (state.equals("MISS")) {
                return mid;
            }
            return increaseDir ?
                    binarySearch(fix, mid + 1, to, isXAxeFixed, increaseDir, in) :
                    binarySearch(fix, from, mid - 1, isXAxeFixed, increaseDir, in) ;
        } else if (state.equals("CENTER")) {
            return -1;
        } else {
            return increaseDir ?
                    binarySearch(fix, from, mid - 1, isXAxeFixed, increaseDir, in):
                    binarySearch(fix, mid + 1, to, isXAxeFixed, increaseDir, in) ;
        }
    }

}
