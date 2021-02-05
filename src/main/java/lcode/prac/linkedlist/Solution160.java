package lcode.prac.linkedlist;
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 */
public class Solution160 {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        
        ListNode a = headA;
        ListNode b = headB;
        
        while ( a != b ) {
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        } 
        return a;
    }
}