package codejam.y2019.r1a.b;
// Remove package line for submit

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        int N = in.nextInt();
        int M = in.nextInt();

        for (int i = 0; i < T; i++) {

            // ask separately 5, 7, 9, 11, 13, 16, 17
            int[] questions = new int[] {5, 7, 9, 11, 13, 16, 17};
            int[] mods = new int[7];
            for (int q = 0; q < questions.length; q++) {
                int[] toAsk = new int[18];
                String str = generateToAsk(toAsk, questions[q]);
                System.out.println(str);
                int sum = 0;
                for (int k = 0; k < 18; k++) {
                    sum += in.nextInt();
                }
                mods[q] = sum % questions[q];
            }
            int res = 1;
            for (; res <= M; res++) {
                boolean found = true;
                for (int k1 = 0; k1 < questions.length; k1++) {
                    int question = questions[k1];
                    if (res % question != mods[k1]) {
                        found = false;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
            System.out.println(res);
            //System.err.println(res);
            int correct = in.nextInt();
//            if (correct != 1) {
//                throw new IllegalStateException("should not happen");
//            }

        }
        in.close();
    }

    private static String generateToAsk(int[] toAsk, int val) {
        Arrays.fill(toAsk, val);
        String str = Arrays.stream(toAsk).boxed().map(Object::toString).collect(Collectors.joining(" "));
        return str;
    }
}
