package listnode;

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode() {}
    public ListNode(int val) { this.val = val; }
    public ListNode(int val, ListNode next) { this.val = val; this.next = next; }

    public static ListNode addAtHead(ListNode head, int val) {
        ListNode newNode = new ListNode(val);
        newNode.next = head;
        return newNode;
    }

    public static void addAtTail(ListNode head, int val) {
        ListNode current = head;
        while(current.next != null) {
            current = current.next;
        }
        ListNode newNode = new ListNode(val);
        current.next = newNode;
    }
    
    public static void printList(ListNode head) {
        ListNode curr = head;
        while(curr != null) {
            System.out.print(String.format("%d-", curr.val));
            curr = curr.next;
        }
        System.out.println("");
    }

    public static ListNode copyList(ListNode head) {
        if (head == null) return head;
        ListNode dummy = new ListNode();
        ListNode current = dummy;

        while(head != null) {
            current.next = new ListNode(head.val);
            current = current.next;
            head = head.next;
        }

        return dummy.next;
    }
}
