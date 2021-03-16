package codejam.y2020.r1a.a;

// Remove package line for submit

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int T = in.nextInt();
        in.nextLine();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            String result = "*";

            List<String> middle = new ArrayList<>();
            String starting = "*";
            String ending = "*";

            for (int j = 0; j < N; j++) {
                String pattern = in.next();

                if (starting != null && ending != null) {

                    int lastIndex = pattern.lastIndexOf("*");
                    ending = mergeEnding(pattern.substring(lastIndex), ending);

                    int firstIndex = pattern.indexOf("*");
                    starting = mergeStarting(pattern.substring(0, firstIndex+1), starting);

                    if (firstIndex < lastIndex) {
                        String middlePart = pattern.substring(firstIndex + 1, lastIndex);
                        String[] split = middlePart.split("\\*");
                        for (int k = 0; k < split.length; k++) {
                            if (!split[k].isEmpty())
                                middle.add(split[k]);
                        }
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + (starting == null || ending == null ? result : fill(starting, ending, middle)));
        }
        in.close();
    }

    private static String fill(String starting, String ending, List<String> middle) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < starting.length(); i++) {
            if (starting.charAt(i) != '*') {
                sb.append(starting.charAt(i));
            }
        }

        for (String s : middle) {
            sb.append(s);
        }

        for (int i = 0; i < ending.length(); i++) {
            if (ending.charAt(i) != '*') {
                sb.append(ending.charAt(i));
            }
        }
        return sb.toString();
    }

    private static String mergeStarting(String pattern1, String pattern2) {
        int diff = pattern1.length() - pattern2.length();
        if (diff > 0) {
            pattern2 = pattern2 + "*".repeat(diff) ;
        } else {
            pattern1 = pattern1 + "*".repeat(-diff) ;
        }

        int first = pattern1.length() - 1, second = pattern2.length() - 1;
        while (first >= 0  && second >= 0) {
            if (pattern1.charAt(first) == '*' || pattern2.charAt(second) == '*') {
                first --;
                second --;
            } else {
                break;
            }
        }
        if ((first < 0 && second < 0) || pattern1.substring(0, first).equals(pattern2.substring(0, second))) {
            return diff > 0 ? pattern1 : pattern2;
        } else {
            return null;
        }
    }

    private static String mergeEnding(String pattern1, String pattern2) {
        int diff = pattern1.length() - pattern2.length();
        if (diff > 0) {
            pattern2 = "*".repeat(diff) + pattern2;
        } else {
            pattern1 = "*".repeat(-diff) + pattern1;
        }

        int first = 0, second = 0;
        while (first < pattern1.length() && second < pattern2.length()) {
            if (pattern1.charAt(first) == '*' || pattern2.charAt(second) == '*') {
                first ++;
                second ++;
            } else {
                break;
            }
        }
        if (pattern1.substring(first).equals(pattern2.substring(second))) {
            return diff > 0 ? pattern1 : pattern2;
        } else {
            return null;
        }
    }
}