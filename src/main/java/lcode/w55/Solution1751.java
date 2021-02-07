package lcode.w55;

import java.util.*;

//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
public class Solution1751 {
    public int maxValue(int[][] events, int k) {
        Map<Integer, List<int[]>> eventsMapEndAt = new HashMap<>();
        Map<Integer, List<int[]>> eventsMapStartAt = new HashMap<>();
        Set<Integer> timeSeriesSet = new HashSet<>();

        for (int[] event: events ) {
            int start = event[0];
            int end = event[1];

            timeSeriesSet.add(start);
            timeSeriesSet.add(end);

            List<int[]> eventsEnds = eventsMapEndAt.getOrDefault(end, new ArrayList<>());
            eventsEnds.add(event);
            eventsMapEndAt.put(end, eventsEnds);

            List<int[]> eventsStarts = eventsMapStartAt.getOrDefault(start, new ArrayList<>());
            eventsStarts.add(event);
            eventsMapStartAt.put(start, eventsStarts);
        }

        timeSeriesSet.add(0);
        List<Integer> timeSeries = new ArrayList<>(timeSeriesSet);
        Collections.sort(timeSeries);

        int[][] maxEventsEndAt = new int[timeSeries.size()][k+1]; // Value, attended meeting number
        int maxValue = 0;
        for (int end = 1; end < timeSeries.size(); end++) {
            int endTime = timeSeries.get(end);
            int maxForThisEnd = 0;
            int[] maxLocalAttended = new int[k+1];
            for (int[] event : eventsMapEndAt.getOrDefault(endTime, Collections.emptyList())) {
                int start = event[0];
                int value = event[2];

                for (int attended = 0 ; attended < k; attended ++) {
                    int previousIndex = getIndex(timeSeries, start-1);
                    if (attended == 0 || maxEventsEndAt[previousIndex][attended] != 0) {
                        int local = maxEventsEndAt[previousIndex][attended] + value;
                        if (maxLocalAttended[attended + 1] < local){
                            maxLocalAttended[attended + 1] = local;
                        }
                    }
                }
            }

            for  (int i = 0; i < k+1; i++) {
                maxEventsEndAt[end][i] = Math.max(maxLocalAttended[i], maxEventsEndAt[end - 1][i]);
                if (maxLocalAttended[i] > maxValue) {
                    maxValue = maxLocalAttended[i];
                }
            }
        }

        return maxValue;
    }

    private final int getIndex(List<Integer> list, int value) {
        int ret = Collections.binarySearch(list, value);
        return ret < 0 ? -ret -2 : ret;
    }
}
