package lcode.w48;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Solution1798 {

    public int getMaximumConsecutive(int[] coins) {
        List<Integer> sorted = Arrays.stream(coins).sorted().boxed().collect(Collectors.toList());
        int currentSum = 0;

        for (Integer coin : sorted) {
            if (currentSum >= coin - 1) {
                currentSum += coin;
            } else {
                break;
            }
        }
        
        return currentSum+1;
    }

}
