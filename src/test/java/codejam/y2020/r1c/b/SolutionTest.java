package codejam.y2020.r1c.b;
import org.junit.Test;

import java.io.File;
import java.util.Scanner;

import static org.junit.Assert.*;

public class SolutionTest {

    @Test
    public void test1() throws Exception {
        Scanner scanner = new Scanner(new File("src/test/java/codejam/y2020/r1c/b/sample.in.txt"));
        Solution.decode(scanner);
    }
}