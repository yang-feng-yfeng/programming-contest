package codejam.y2019.r1b.a;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int P = in.nextInt();
            int Q = in.nextInt();
            int[][] matrix = new int[Q+1][Q+1];

            for (int i = 0; i < P; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                String direc = in.next();
                update(x, y, direc, matrix, Q);
            }

            int[] cord = new int[2];
            int max = -1;
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    if (max < matrix[i][j]) {
                        cord[0] = i;
                        cord[1] = j;
                        max = matrix[i][j];
                    }
                }
            }


            System.out.println("Case #" + (t+1) + ": " + cord[0] + " " + cord[1]);
        }
        in.close();
    }

    private static void update(int x, int y, String direc, int[][] matrix, int Q) {

        if ("N".equals(direc)) {
            for (int i = 0; i < x; i++) {
                for (int j = y + 1; j <= Q && j <= (x + y - i); j++) {
                    matrix[i][j]++;
                }
            }
            for (int i = y + 1; i <= Q; i++) {
                matrix[x][i]++;
            }
        } else if ("S".equals(direc)) {
            for( int i = 0; i < x; i++) {
                for (int j = 0; j < y && j >= (i + y - x); j++){
                    matrix[i][j]++;
                }
            }
            for( int i = 0; i < y; i++) {
                matrix[x][i]++;
            }
        } else if ("W".equals(direc)) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; (j <= Q && j <= (x + y - i))|| (j < y && j >= (i + y - x)); j++) {
                    matrix[i][j]++;
                }
            }
            for( int i = 0; i < x; i++) {
                matrix[i][y]++;
            }
        } else if ("E".equals(direc)) {
//            for (int i = x + 1; i <= Q /2; i++) {
//                for (int j = 0; j )
//            }
        }
    }
}
