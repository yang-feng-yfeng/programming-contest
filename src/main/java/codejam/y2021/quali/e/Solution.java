package codejam.y2021.quali.e;
// Remove package line for submit

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        cheater(in);
        in.close();
    }

    public static void cheater(Scanner in) {
        int T = in.nextInt();
        int p = in.nextInt();

        for (int i = 0; i < T; i++) {
            double[] players = new double[100];
            double[] questions = new double[10000];

            int[] correctPlayers = new int[100];
            int[] correctQuestions = new int[10000];

            double[] diffs = new double[100];
            List<String> scores = new ArrayList<>();
            for (int j = 0; j < 100; j++) {
                String score = in.next();
                scores.add(score);
                for (int k = 0; k < 10000; k++) {
                    if (score.charAt(k) == '1') {
                        correctPlayers[j]++;
                        correctQuestions[k]++;
                    }
                }
            }

            for (int i1 = 0; i1 < 100; i1++) {
                double a = correctPlayers[i1]/10000.0;
                players[i1] = reverseF(a) / 2.0;
                players[i1] = (players[i1] < -3.0) ? -3.0 : ((players[i1] >3 ) ? 3 : players[i1]) ;
            }

            for (int i1 = 0; i1 < 10000; i1++) {
                double a = correctQuestions[i1]/100.0;
                questions[i1] = reverseF(a) / 2.0;
                questions[i1] = (questions[i1] < -3.0) ? -3.0 : ((questions[i1] >3 ) ? 3 : questions[i1]) ;
            }

            int[] sortedQuestions = IntStream.range(0, correctQuestions.length)
                    .boxed()
                    .sorted(Comparator.comparingInt(d -> correctQuestions[d]))
                    .mapToInt(ele -> ele)
                    .toArray();


            for (int j = 0; j < 100; j++) {
                for (int k = 0; k < 500; k++) {
                    int q = sortedQuestions[k];
                    double x = players[j] - questions[q];
                    double tp = f(x);
                    double realp = scores.get(j).charAt(q) == '1' ? 1.0 : 0.0;
                    diffs[j] += realp - tp;
                }
                for (int k = 0; k < 500; k++) {
                    int q = sortedQuestions[questions.length - 1 - k];
                    double x = players[j] - questions[q];
                    double tp = f(x);
                    double realp = scores.get(j).charAt(q) == '1' ? 1.0 : 0.0;
                    diffs[j] += Math.abs(tp - realp);
                }
            }

            int maxIndex= 0;
            double max=-1;

            for (int k = 0; k < diffs.length; k++) {
                if (diffs[k] > max) {
                    max = diffs[k];
                    maxIndex = k;
                }
            }
            System.out.println("Case #" + (i+1) + ": " + (1+maxIndex));
        }
    }

    public static double f(double x) {
        return 1.0 / (1 + Math.exp(-x));
    }

    public static double reverseF(double y) {
        return Math.log(y / (1-y));
    }
}
