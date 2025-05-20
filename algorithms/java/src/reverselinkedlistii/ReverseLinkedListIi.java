
/**
 * Title: Reverse Linked List II
 * CreateTime: 2025-05-20
 * Difficulty: Medium
 * Likes: 12225
 * Dislikes: 707
 * Topic Tags: Linked List
 *
 * Problem description:
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 *  
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * Example 2:
 * 
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 * 
 *  
 * Constraints:
 * 
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 * 
 *  
 * Follow up: Could you do it in one pass?
 *
 * Hints:

 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
package reverselinkedlistii;

class Solution {
    public static class ListNode {
        int val; 
        ListNode next;

        ListNode(){}
        ListNode(int val) {
            this.val = val;
        }
        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

        ListNode addAtHead(ListNode head, int val) {
            ListNode newNode = new ListNode(val);
            newNode.next = head;
            return newNode;
        }
        
        void printList(ListNode head) {
            ListNode curr = head;
            while(curr != null) {
                System.out.print(String.format("%d-", curr.val));
                curr = curr.next;
            }
            System.out.println("");
        }
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) return head;
        ListNode dummy = new ListNode();
        dummy.next = head;

        ListNode leftTail = dummy;
        ListNode leftNode = head;

        for (int i = 1; i < left; i++) {
            leftTail = leftTail.next;
            leftNode = leftNode.next;
        }

        // dummy->...->leftTail->prev->...->leftNode->curr->...
        ListNode curr = leftNode;
        ListNode prev = null;

        for (int i = 0; i <= right-left; i++) {
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }

        leftTail.next = prev;
        leftNode.next = curr;

        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head = head.addAtHead(head, 2);
        head = head.addAtHead(head, 3);
        head = head.addAtHead(head, 4);   
        head.printList(head);

        Solution solution = new Solution();

        ListNode revListNode = solution.reverseBetween(head, 2, 3);
        revListNode.printList(revListNode);
    }
}