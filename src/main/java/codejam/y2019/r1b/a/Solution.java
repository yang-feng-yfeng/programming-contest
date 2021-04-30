package codejam.y2019.r1b.a;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        Map<String, Integer> direcMap = new HashMap<>();
        direcMap.put("N", 1);
        direcMap.put("S", 2);
        direcMap.put("W", 3);
        direcMap.put("E", 4);

        for (int t = 0; t < T; t++) {
            int P = in.nextInt();
            int Q = in.nextInt();
            List<int[]> xlist = new ArrayList<>();
            List<int[]> ylist = new ArrayList<>();

            for (int i = 0; i < P; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                String dir = in.next();
                if ("N".equals(dir)) {
                    ylist.add(new int[]{y+1, 1});
                } else if ("S".equals(dir)) {
                    ylist.add(new int[]{0, 1});
                    ylist.add(new int[]{y, -1});
                } else if ("W".equals(dir)) {
                    xlist.add(new int[] {0, 1});
                    xlist.add(new int[] {x, -1});
                } else if ("E".equals(dir)) {
                    xlist.add(new int[] {x+1, 1});
                }
            }
            xlist.sort((a,b) -> (a[0] - b[0] == 0 ? a[1] - b[1] : a[0] - b[0]));
            ylist.sort((a,b) -> (a[0] - b[0] == 0 ? a[1] - b[1] : a[0] - b[0]));

            int maxX = -1;
            int idxX = 0;
            int maxY = -1;
            int idxY = 0;

            int currentX = 0;
            int currentY = 0;
            for (int[] e : xlist) {
                int x = e[0];
                int add = e[1];
                currentX += add;
                if (currentX > maxX) {
                    maxX = currentX;
                    idxX = x;
                }
            }

            for (int[] e : ylist) {
                int y = e[0];
                int add = e[1];
                currentY += add;
                if (currentY > maxY) {
                    maxY = currentY;
                    idxY = y;
                }
            }
            System.out.println("Case #" + (t+1) + ": " + idxX + " " + idxY);
        }
        in.close();
    }
}
