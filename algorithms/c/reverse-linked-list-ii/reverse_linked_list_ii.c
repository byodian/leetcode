
/**
 * Title: Reverse Linked List II
 * CreateTime: 2025-05-15
 * Difficulty: Medium
 * Likes: 12217
 * Dislikes: 706
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
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween1(struct ListNode* head, int left, int right) {
  if (head == NULL || left == right) 
    return head;

  // 头节点指向，新链表的头结点
  struct ListNode* new_head = head;
  // 反转区间前一个结点，left-1 位置
  struct ListNode* left_tail = NULL;
  // left 位置，反转区间的第一个结点，反转后是区间的尾结点
  struct ListNode* left_node = head;

  // left 为1 表示从头节点开始还是反转，需要特殊处理 head 节点
  // 因为 head 节点在不断变化，因此需要更新 new_head 的指向，否则会丢失 head 节点
  if (left == 1) {
    // 此条件没有用到 left_tail 结点
    struct ListNode* current = left_node;
    struct ListNode* prev = NULL;
    for (int i = 1; i <= right; i++) {
      struct ListNode* next_node = current->next;
      current->next = prev;
      prev = current;
      current = next_node;
    }

    new_head = prev;
    left_node->next = current;
  } else {
    for (int i = 1; i < left; i++) {
      left_tail = left_node;
      left_node = left_node->next;
    }

    struct ListNode* current = left_node;
    struct ListNode* prev = NULL;

    for (int i = 0; i <= right - left; i++) {
      struct ListNode* next_node = current->next;
      current->next = prev;
      prev = current;
      current = next_node;
    }

    left_tail->next = prev;
    left_node->next = current;
  }

  return new_head;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
  if (head == NULL || left == right) 
    return head;

  // 使用虚拟结点，简化边界处理，统一代码逻辑
  // 无需处理 if(left == 1) 特殊分支，避免特殊判断
  struct ListNode dummy;
  dummy.next = head;

  // 反转区间前一个结点，left-1 位置
  struct ListNode* left_tail = &dummy;
  // left 位置，反转区间的第一个结点，反转后是区间的尾结点
  struct ListNode* left_node = head;

  for (int i = 1; i < left; i++) {
    left_tail = left_tail->next;
    left_node = left_node->next;
  }

  struct ListNode* current = left_node;
  struct ListNode* prev = NULL;

  for (int i = 0; i <= right - left; i++) {
    struct ListNode* next_node = current->next;
    current->next = prev;
    prev = current;
    current = next_node;
  }

  left_tail->next = prev;
  left_node->next = current;

  return dummy.next;
}

struct ListNode* createNode(int val) {
  struct ListNode* new_node = malloc(sizeof(struct ListNode));
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

// 头插法新增结点
void addAtHead(struct ListNode** head, int val) {
  struct ListNode* new_node = createNode(val);
  // 在头结点前插入新结点
  new_node->next = *head;
  // 更新头结点
  *head = new_node;
}

void printList(struct ListNode* head) {
  struct ListNode* curr = head;
  while (curr) {
    printf("%d-", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct ListNode* head = createNode(0);
  addAtHead(&head, 1);
  addAtHead(&head, 2);
  addAtHead(&head, 3);
  addAtHead(&head, 4);
  addAtHead(&head, 5);
  printList(head);
  struct ListNode* reverse_head = reverseBetween(head, 1, 3);
  printList(reverse_head);

  struct ListNode* reverse_head_2 = reverseBetween(reverse_head, 2, 4);
  printList(reverse_head_2);

  return 0;
}