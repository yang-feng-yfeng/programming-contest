package lcode.prac.math;

import java.util.Deque;
import java.util.LinkedList;

// https://leetcode.com/problems/basic-calculator/
class Solution224 {
    public int calculate(String s) {
        String allOperator = s.replace(" ", "");
        Deque<String> stack = new LinkedList<>();
        StringBuilder curNb = new StringBuilder();
        
        for (char next : allOperator.toCharArray()) {
            if (')' == next) {
                if (curNb.length() != 0) {
                    stack.push(curNb.toString());
                    curNb = new StringBuilder();        
                } 
                String v = String.valueOf(calculateStack(stack));
                stack.push(v);
            } else if (
                  '(' == next ||
                  '+' == next ||
                  '-' == next ) {
                if (curNb.length() != 0) {
                    stack.push(curNb.toString());
                    curNb = new StringBuilder();        
                }
                stack.push(String.valueOf(next));
            } else {
                curNb.append(next);
            }
        }
        if (curNb.length() != 0) {
            stack.push(curNb.toString());
        }
        return calculateStack(stack);
    }
    
    private int calculateStack (Deque<String> stack) {
        int result = 0;
        int previous = 0;
        String v ;
        while (!stack.isEmpty()) {
            v = stack.pop();
            if (v.equals("+")) {
                result += previous;
                previous = 0;
            } else if (v.equals("-")) {
                result -= previous;
                previous = 0;
            } else if (v.equals("(")) {
                break;
            } else {
                previous = Integer.parseInt(String.valueOf(v));
            }
        }
        result += previous;
        return result;
    }
}