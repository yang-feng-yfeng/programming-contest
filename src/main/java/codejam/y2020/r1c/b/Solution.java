package codejam.y2020.r1c.b;
// Remove package line for submit

import java.util.*;
import java.util.stream.Collectors;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        decode(in);
        in.close();
    }

    public static void decode(Scanner in) {
        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int U = in.nextInt();
            Map<Character, Long> counts = new HashMap<>();
            for (int j = 0; j < (Math.pow(10, 4)); j++) {
                long num = in.nextLong();
                String encoded = in.next();
                char c = encoded.charAt(0);
                Long count = counts.getOrDefault(c, 0L);
                counts.put(c, count+1);
                if (encoded.length() >= 2) {
                    c = encoded.charAt(1);
                    count = counts.getOrDefault(c, 0L);
                    counts.put(c, count+1);
                }


            }

            List<Character> characters = counts.entrySet().stream().sorted((e1, e2) -> Long.compare(e2.getValue(), e1.getValue())).map(Map.Entry::getKey).collect(Collectors.toList());
            StringBuilder sb = new StringBuilder();
            sb.append(characters.get(9));
            for (int k = 0; k < 9; k++) {
                sb.append(characters.get(k));
            }

            System.out.println("Case #" + (i+1) + ": " + sb.toString());
        }
    }
}
