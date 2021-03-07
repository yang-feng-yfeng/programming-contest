package lcode.w47;

import java.util.*;

// https://leetcode.com/problems/count-pairs-of-nodes/submissions/
public class Solution1782 {

    // Memory limit exceed
    public int[] countPairs1(int n, int[][] edges, int[] queries) {
        int[] nodeCount = new int[n];
        int[][] edgeCount = new int[n][n];

        for (int[] edge : edges) {
            nodeCount[edge[0]]++;
            nodeCount[edge[1]]++;

            edgeCount[edge[0]][edge[1]]++;
            edgeCount[edge[1]][edge[0]]++;
        }

        Map<Integer, Integer> incidentCount = new TreeMap<>();
        int allEdges = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int v = 0;
                v += nodeCount[i];
                v += nodeCount[j];

                int v3 = edgeCount[i][j];

                int count = incidentCount.getOrDefault((v-v3), 0);
                incidentCount.put((v-v3), count+1);
                allEdges++;
            }
        }

        Map<Integer, Integer> incidentSum = new HashMap<>();
        int sum = 0;
        for (Map.Entry<Integer, Integer> entry : incidentCount.entrySet()) {
            sum += entry.getValue();
            incidentSum.put(entry.getKey(), sum);
            //System.out.println(" v: " + entry.getKey() + " sum: " + sum);
        }

        int[] res = new int[queries.length];
        for (int i = 0 ; i < queries.length; i++) {
            int q = queries[i];
            while (!incidentSum.containsKey(q) && q > 0) {
                q--;
            }
            res[i] = allEdges - ( q == 0 ? 0 : incidentSum.get(q));
            //System.out.println(" res: " + i + " count: " + res[i]);
        }
        return res;
    }

    // 2 step calculation
    // Store degree in array
    // Store edge in map with a * 20000 + b as maximum is 20000
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        int[] degree = new int[n];
        Map<Integer, Integer> cnt = new HashMap<>();

        for (int[] ed : edges) {
            degree[--ed[0]] ++;
            degree[--ed[1]] ++;

            if (ed[0] > ed[1]) {
                int tmp = ed[0];
                ed[0] = ed[1];
                ed[1] = tmp;
            }

            cnt.put(ed[0] * 20000 + ed[1], cnt.getOrDefault(ed[0] * 20000 + ed[1], 0) + 1);
        }

        int[] sorted = degree.clone();
        Arrays.sort(sorted);

        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int ans = 0;

            for (int l = 0, r = sorted.length - 1; l < r;) {
                if (sorted[l] + sorted[r] > queries[i]) {
                    ans += r - l;
                    r --;
                } else {
                    l ++;
                }
            }

            for (int k : cnt.keySet()) {
                int fi = k / 20000;
                int se = k % 20000;
                if (degree[fi] + degree[se] > queries[i] && degree[fi] + degree[se] - cnt.get(k) <= queries[i])
                    ans --;
            }
            res[i] = ans;
        }
        return res;
    }

}
