package codejam.y2021.r1a.c;
// Remove package line for submit

import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            int Q = in.nextInt();
            String[] answers = new String[N];
            int[] score = new int[N];


            int bigger = -1;
            int bigIdx = 0;
            for (int i = 0; i < N; i++) {
                answers[i] = in.next();
                score[i] = in.nextInt();
                if (score[i] > bigger) {
                    bigger = score[i];
                    bigIdx = i;
                }
            }
            int nbDiff = 0;
            int nbSame = 0;

            Set<Integer> sameDigit = new HashSet<>();

            if (N > 1) {
                for (int i = 0; i < Q; i++) {
                    if (answers[0].charAt(i) == answers[1].charAt(i) ) {
                        sameDigit.add(i);
                        nbSame ++;
                    } else {
                        nbDiff ++;
                    }
                }

                int actualCorSamePart = 0;
                int actualCorDiffPart0 = 0;
                int actualCorDiffPart1 = 0;

                for (int same = nbSame; same > 0; same--) {
                    int remind0 = score[0] - same;
                    int remind1 = score[1] - same;
                    if (remind0 + remind1 == nbDiff) {
                        actualCorSamePart = same;
                        actualCorDiffPart0 = remind0;
                        actualCorDiffPart1 = remind1;
                        break;
                    }
                }

                int maxScore = 0;
//            String maxAnswer = "";
                char[] maxAnswerChar = new char[Q];

                if (actualCorSamePart <= nbSame/2) {
                    // Should reverse
                    maxScore += nbSame - actualCorSamePart;
                    maxScore += bigger - actualCorSamePart;

                    for (int i = 0; i < Q; i++) {
                        if (sameDigit.contains(i)) {
                            maxAnswerChar[i] = (answers[bigIdx].charAt(i) == 'T' )? 'F' : 'T';
                        } else {
                            maxAnswerChar[i] = answers[bigIdx].charAt(i);
                        }
                    }
                } else {
                    maxScore = bigger;
                    for (int i = 0; i < Q; i++) {
                        maxAnswerChar[i] = answers[bigIdx].charAt(i);
                    }

                }
                System.out.println("Case #" + (t+1) + ": " + new String(maxAnswerChar) + " " + maxScore + "/1");
            }

            else {
                System.out.println("Case #" + (t+1) + ": " + answers[0] + " " + score[0] + "/1");
            }
        }
        in.close();
    }
}
