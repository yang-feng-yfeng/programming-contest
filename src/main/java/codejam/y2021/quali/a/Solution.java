package codejam.y2021.quali.a;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int n = in.nextInt();
            int[] toS = new int[n];
            for (int j = 0; j < n; j++) {
                toS[j] = in.nextInt();
            }
            int result = 0;
            for (int k = 0; k < n - 1; k++) {
                int index = findIndex(toS, k, k+1);
                result += index - k + 1;
                reverse(toS, k, index);
            }
            System.out.println("Case #" + (i+1) + ": " + result);
        }
        in.close();
    }

    public static void reverse(int[] arr, int from, int to) {
        if (from == to) {
            // do nothing
        } else {
            while (to > from) {
                swap(arr, from++, to--);
            }
        }
    }

    public static void swap(int[] arr, int a, int b) {
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }

    public static int findIndex(int[] arr, int from, int value){
        for (int i = from; i < arr.length; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }
}
