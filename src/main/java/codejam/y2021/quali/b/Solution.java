package codejam.y2021.quali.b;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int X = in.nextInt();
            int Y = in.nextInt();
            String S = in.next();


            int res = 0;
            if (X > 0 && Y > 0) {
                int start =0, end = 0;
                char[] ca = S.toCharArray();
                for (;end < S.length();) {
                    if (isQuestionMark(ca[start]) ^ isQuestionMark(ca[end])) {
                        // C...? or ?...C
                        if (isQuestionMark(ca[end])) {
                            res += calculateMinWithOut(X, Y, S.substring(start, end));
                        } else if (!isQuestionMark(ca[end])) {
                            if (start != 0) {
                                res += calculateMin(X, Y, S.substring(start - 1, end + 1));
                            } else {
                                res += calculateHeadQuestionMark(X, Y, S.substring(start, end));
                            }
                        }
                        start = end;
                        end ++;
                    } else {
                        end++;
                    }
                }
                if (start < end - 1) {
                    // 1: ??...? 2 C...J
                    if (isQuestionMark(ca[start])) {
                        if (start != 0) {
                            res += calculateEndQuestionMark(X, Y, S.substring(start - 1));
                        } else {
                            res += calculateAllQuestionMark(X, Y, S.substring(start));
                        }
                    } else {
                        res += calculateMinWithOut(X, Y, S.substring(start));
                    }
                }
            } else {
                // DO it later
            }
            System.out.println("Case #" + (i+1) + ": " + res);
        }
        in.close();
    }

    private static int calculateAllQuestionMark(int x, int y, String substring) {
        if (x > 0 && y > 0) {
            return 0;
        }
        return -1;
    }

    private static int calculateEndQuestionMark(int X, int Y, String substring) {
        if (X > 0 && Y > 0) {
            return 0;
        }
        return -1;
    }

    public static boolean isQuestionMark(char c) {
        return c == '?';
    }

    public static int calculateHeadQuestionMark(int X, int Y, String sub) {
        if (X > 0 && Y > 0) {
            return 0;
        }
        return -1;
    }

    public static int calculateMinWithOut(int X, int Y, String sub) {
        char[] ca = sub.toCharArray();
        int res = 0;
        for (int i = 1; i < ca.length; i++) {
            if (ca[i] == 'C' && ca[i-1] == 'J') {
                res += Y;
            } else if (ca[i] == 'J' && ca[i-1] == 'C') {
                res += X;
            }
        }
        return res;
    }

    public static int calculateMin(int X, int Y, String sub) {
         // C????J type
        char first = sub.charAt(0);
        char last = sub.charAt(sub.length() - 1);
        if ((first != 'C' && first != 'J') || (last != 'C' && last != 'J')) {
            throw new IllegalArgumentException("sub string is not correct format");
        } else {
            if (X > 0 && Y > 0) {
                if ( first == last) {
                    return 0;
                } else {
                    if (first == 'C') {
                        // CJ
                        return X;
                    } else {
                        return Y;
                    }
                }
            }
        }
        return 0;
    }

}
