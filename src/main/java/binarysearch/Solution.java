package binarysearch;

import java.util.*;
import java.util.stream.Collectors;

public class Solution {
    public int solve(int n) {
        String s = Integer.toString(n);

        int i;
        for ( i = s.length() - 2; i >= 0 ; i-- ) {
            if ( s.charAt(i) < s.charAt(i+1)) {
                break;
            }
        }
        if (i == -1) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            return Integer.parseInt(new String(ca));
        }

        char[] ca = s.toCharArray();

        int toRep = i;
        for (i = s.length() - 1; i >= 0 ; i-- ) {
            if (s.charAt(i) > s.charAt(toRep)) {
                char tmp = ca[i];
                ca[i] = ca[toRep];
                ca[toRep] = tmp;
                break;
            }
        }
        Arrays.sort(ca, toRep + 1, ca.length);
        return Integer.parseInt(new String(ca));
    }
}
