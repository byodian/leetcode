/**
 * Title: Merge Two Sorted Lists
 * CreateTime: 2025-06-17
 * Difficulty: Easy
 * Likes: 23409
 * Dislikes: 2300
 * Topic Tags: Linked List, Recursion
 *
 * Problem description:
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 *  
 * Example 1:
 * 
 * 
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * Example 2:
 * 
 * Input: list1 = [], list2 = []
 * Output: []
 * 
 * Example 3:
 * 
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 * 
 *  
 * Constraints:
 * 
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 * 
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
package mergetwosortedlists;

import listnode.ListNode;

import static listnode.ListNode.*;

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null && list2 == null) {
            return null;
        } else if (list1 == null) {
            return list2;
        } else if (list2 == null) {
            return list1;
        }  

        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while(list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                temp.next = list1;
                temp = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                temp = list2;
                list2 = list2.next;
            }
        }

        if (list1 != null) {
            temp.next = list1;
        }
        
        if (list2 != null) {
            temp.next = list2;
        }
        
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode list1 = new ListNode(0);
        ListNode.addAtTail(list1, 1);
        ListNode.addAtTail(list1, 3);


        ListNode list2 = new ListNode(4);
        ListNode.addAtTail(list2, 5);
        ListNode.addAtTail(list2, 6);

        Solution solution = new Solution();
        printList(solution.mergeTwoLists(copyList(list1), copyList(list2)));
        printList(solution.mergeTwoLists(null, copyList(list2)));
        printList(solution.mergeTwoLists(copyList(list1), null));
    }
}