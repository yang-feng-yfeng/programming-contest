package lcode.w44;
// https://leetcode.com/contest/biweekly-contest-44/problems/minimum-number-of-people-to-teach
class Solution1733 {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        int minToTeach = 505;
        for (int l = 1; l <= n ; l++) {
            int[][] userLangMatrix = new int[505][505];
            // set language
            for (int i = 0; i < languages.length; i++) {
                for (int j: languages[i]) {
                    userLangMatrix[i][j-1] = 1;
                }
            }

            int currentLang = l-1;
            int currentToTeach = 0;
            // Test friendships
            for (int[] friendship : friendships) {
                int user1 = friendship[0] - 1;
                int user2 = friendship[1] - 1;

                if (!canTalk(userLangMatrix, user1, user2, n)) {
                    if (userLangMatrix[user1][currentLang] == 0) {
                        userLangMatrix[user1][currentLang] = 1;
                        currentToTeach ++;
                    }
                    if (userLangMatrix[user2][currentLang] == 0) {
                        userLangMatrix[user2][currentLang] = 1;
                        currentToTeach ++;
                    }
                }
            }
            if (minToTeach > currentToTeach) {
                minToTeach = currentToTeach;
            }
        }
        return minToTeach;
    }

    public boolean canTalk (int[][] userLangMatrix, int user1, int user2, int n) {
        for (int i = 0 ; i < n ; i ++) {
            if (userLangMatrix[user1][i] == 1 && userLangMatrix[user2][i] == 1) {
                return true;
            }
        }
        return false;
    }
}