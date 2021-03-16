package codejam.y2020.r1b.a;
// Remove package line for submit

import java.util.Arrays;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int X = in.nextInt();
            int Y = in.nextInt();
            // Reverse the direction at the end
            String binaryX = X > 0 ? Integer.toBinaryString(X) : Integer.toBinaryString(-X);
            String binaryY = Y > 0 ? Integer.toBinaryString(Y) : Integer.toBinaryString(-Y);

            int diff = binaryX.length() - binaryY.length();
            if (diff > 0) {
                binaryY = "0".repeat(diff) + binaryY;
            } else if (diff < 0) {
                binaryX = "0".repeat(-diff) + binaryX;
            }


            boolean[] bx = new boolean[binaryX.length() + 1];
            for (int i1 = 1; i1 <= binaryX.length(); i1++) {
                bx[i1] = binaryX.charAt(i1-1) == '1';
            }
            boolean[] by = new boolean[binaryY.length() + 1];
            for (int i1 = 1; i1 <= binaryY.length(); i1++) {
                by[i1] = binaryY.charAt(i1-1) == '1';
            }

            int maxLength = Math.max(binaryX.length(), binaryY.length());

            int[] resultX = new int[maxLength + 1];
            int[] resultY = new int[maxLength + 1];



            String res = "";
            boolean xSurplus=false, ySurplus=false;

            for (int index = maxLength; index >= 0 && res.isEmpty(); index--) {
                if (index == maxLength) {
                    // last digit
                    if ((bx[index] & by[index]) || (!bx[index] & !by[index])) {
                        res = "IMPOSSIBLE";
                    }
                    else if (bx[index]) {
                        resultX[index] = 1;
                    } else {
                        resultY[index] = 1;
                    }
                } else if (index != 0){
                    if ((!bx[index] & !by[index] )) {
                        if ( (!xSurplus && !ySurplus) || xSurplus && ySurplus) {
                            res = "IMPOSSIBLE";
                        } else {
                            if (xSurplus) {
                                resultX[index] = 1;
                                xSurplus = false;
                            } else {
                                resultY[index] = 1;
                                ySurplus = false;
                            }
                        }
                    } else if (bx[index] & by[index]) {
                        if (xSurplus && ySurplus) {
                            res = "IMPOSSIBLE";
                        } else if (!bx[index + 1]) {
                            resultX[index] = 1;
                            int k = index;
                            while (k < resultY.length && resultY[k] == 0 ) {
                                k++;
                            }
                            if (resultY[k] == 1) {
                                resultY[k] = -1;
                                ySurplus = true;
                            } else if (resultY[k] == 0){
                                res = "IMPOSSIBLE";
                            }

                        } else if (!by[index + 1]) {
                            resultY[index] = 1;
                            int k = index;
                            while (k < resultX.length && resultX[k] == 0 ) {
                                k++;
                            }
                            if (resultX[k] == 1) {
                                resultX[k] = -1;
                                xSurplus = true;
                            } else if (resultX[k] == 0){
                                res = "IMPOSSIBLE";
                            }
                        } else {
                            // next digit all 1
                            int nextIdx = 1;
                            while (bx[index + nextIdx] && by[index + nextIdx]) {
                                nextIdx ++;
                            }
                            if (!bx[index + nextIdx]) {
                                resultX[index] = 1;
                            } else {
                                resultY[index] = 1;
                            }
                        }
                    } else if (bx[index]) {
                        if (ySurplus) {
                            res = "IMPOSSIBLE";
                        } else {
                            resultX[index] = 1;
                        }
                    } else {
                        if (xSurplus) {
                            res = "IMPOSSIBLE";
                        } else {
                            resultY[index] = 1;
                        }
                    }
                } else if (index == 0) {
                    if (xSurplus && ySurplus) {
                        res = "IMPOSSIBLE";
                    } else if (xSurplus) {
                        resultX[0] = 1;
                    } else if (ySurplus){
                        resultY[0] = 1;
                    }
                }
            }
            String result = writeRes(res, resultX, resultY, X >= 0, Y >= 0);

            System.out.println("Case #" + (i+1) + ": " + result);
        }
        in.close();
    }

    private static String writeRes(String res, int[] resultX, int[] resultY, boolean isXPositive, boolean isYPositive) {
        char[] result = new char[resultX.length];
        if (res.equals("IMPOSSIBLE")) {
            return res;
        } else {
            for (int i = resultX.length - 1; i >= 0 ; i--) {
                int dir = resultX[i] * (isXPositive ? 1: -1);
                if (dir == 1) {
                    result[result.length - i -1] = 'E';
                } else if (dir == -1) {
                    result[result.length - i -1] = 'W';
                }

            }
            for (int i = resultY.length - 1; i >=0  ; i--) {
                int dir = resultY[i] * (isYPositive ? 1: -1);
                if (dir == 1) {
                    result[result.length - i -1] = 'N';
                } else if (dir == -1) {
                    result[result.length - i -1] = 'S';
                }
            }
            if (result[result.length - 1] == '\0') {
                return new String(Arrays.copyOfRange(result, 0, result.length -1));
            }
            return new String(result);
        }
    }
}
