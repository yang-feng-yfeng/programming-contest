package codejam.y2021.quali.e;

import org.junit.Test;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class SolutionTest {

    @Test
    public void cheater() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("src/main/java/codejam/y2021/quali/e/cheating_detection_sample_ts1_input.txt"));
        Solution.cheater(scanner);
    }
}