package lcode.prac.linkedlist;

// https://leetcode.com/problems/add-two-numbers/
class Solution2 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode currentl1 = new ListNode(0, l1);
        ListNode currentl2 = new ListNode(0, l2);
        ListNode ret = new ListNode(0);
        ListNode currentNode = ret;
        int sup  = 0;
        while (currentl1.next != null && currentl2.next != null) {
            currentl1 = currentl1.next;
            currentl2 = currentl2.next;
            int currentValue = currentl1.val + currentl2.val + sup;
            currentNode.next = new ListNode(currentValue % 10);
            currentNode = currentNode.next;
            sup = currentValue / 10;
        }

        while (currentl1.next != null) {
            currentl1 = currentl1.next;
            int currentValue = currentl1.val + sup;
            currentNode.next = new ListNode(currentValue % 10);
            currentNode = currentNode.next;
            sup = currentValue / 10;
        }

        while (currentl2.next != null) {
            currentl2 = currentl2.next;
            int currentValue = currentl2.val + sup;
            currentNode.next = new ListNode(currentValue % 10);
            currentNode = currentNode.next;
            sup = currentValue / 10;
        }

        if (sup > 0) {
            currentNode.next = new ListNode(1);
        }

        return ret.next;
    }
}
