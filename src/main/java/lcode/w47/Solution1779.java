package lcode.w47;

// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
public class Solution1779 {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int smallValue = 10001;
        int smallIndex = -1;

        for (int i = 0 ; i < points.length; i++) {
            int[] point = points[i];
            if (x == point[0] || y == point[1]) {
                int distance = Math.abs(point[1] - y) + Math.abs(point[0] - x);
                if (distance < smallValue) {
                    smallValue = distance;
                    smallIndex = i;
                }
            }
        }

        return smallIndex;
    }
}
