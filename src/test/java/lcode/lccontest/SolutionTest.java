package lcode.lccontest;

import org.junit.Test;

import static org.junit.Assert.*;

public class SolutionTest {

    @Test
    public void maxGroupNumber() {

        Solution solution = new Solution();
        int number = solution.maxGroupNumber(new int[]{2, 2, 2, 3, 4});


    }

    @Test
    public void minRecSize() {
        Solution sol = new Solution();
        double size = sol.minRecSize(new int[][]{
                {2, 3}, {3, 0}, {4, 1}
        });
    }


    @Test
    public void minRecSize1() {
        Solution sol = new Solution();
        double size = sol.minRecSize(new int[][]{
                {5,2}, {5,-4}, {2,-5}, {4,-1}, {2,0}
        });
        System.out.println(size);
    }

//    [[5,2],[5,-4],[2,-5],[4,-1],[2,0]]
}