
/**
 * Title: Reverse Linked List
 * CreateTime: 2025-05-14
 * Difficulty: Easy
 * Likes: 22866
 * Dislikes: 526
 * Topic Tags: Linked List, Recursion
 *
 * Problem description:
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *  
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * Example 3:
 * 
 * Input: head = []
 * Output: []
 * 
 *  
 * Constraints:
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 * 
 *  
 * Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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

/**
 * helper functions
 */

struct ListNode* createNode(int val) {
  struct ListNode* newnode = malloc(sizeof(struct ListNode));
  newnode->next = NULL;
  newnode->val = val;
  return newnode;
}

void addAtHead(struct ListNode** head, int val) {
  struct ListNode* tmp = *head;
  struct ListNode* newnode = createNode(val);
  newnode->next = tmp;
  *head = newnode;
}

struct ListNode* addAtHead2(struct ListNode* head, int val) {
  struct ListNode* tmp = head;
  struct ListNode* newnode = createNode(val);
  newnode->next = tmp;
  return newnode;
}

void printList(struct ListNode* head) {
  if (head) {
    struct ListNode* current = head;
    while(current) {
      printf("%d-", current->val);
      current = current->next;
    }
  }
  printf("\n");  
}

struct ListNode* deepCopy(struct ListNode* head) {
  struct ListNode* new_head = NULL;
  struct ListNode* new_tail = NULL;
  struct ListNode* cur = head;
  while(cur != NULL) {
    // 分配新节点
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    new_node->val = cur->val;
    new_node->next = NULL;
    // 尾插法构建新链表
    if (new_head == NULL) {
      new_head = new_node;
      new_tail = new_node;
    } else {
      new_tail->next = new_node;
      new_tail = new_node;
    }

    cur = cur->next;
  }

  return new_head;
}

/**
 * helper functions end
 ****************************************** 
 */

struct ListNode* reverseList(struct ListNode* head) {
  if (!head) return head;
  
  struct ListNode* current = head;
  struct ListNode* reverse_head = NULL;
  // 重新分配内存+头插法
  while(current) {
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    new_node->val = current->val;
    new_node->next = reverse_head;
    reverse_head = new_node;
    current = current->next;
  }

  return reverse_head;
}

// 这种方法会修改外部head变量， 导致 head->next 指针指向 NULL
struct ListNode* reverseList2(struct ListNode* head) {
  if (head == NULL || head->next == NULL) return head;

  struct ListNode* cur = head;
  struct ListNode* prev = NULL;
  while(cur != NULL) {
    struct ListNode* next_node = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next_node;
  }
  return prev;
}

/**
 * test cases
 */

int main() {
  struct ListNode* head = NULL;
  for (int i = 0; i < 5; i++) {
    addAtHead(&head, i);
  }
  head = addAtHead2(head, 5);
  printList(head);

  struct ListNode* reverseHead = reverseList(head);
  printList(reverseHead);

  struct ListNode* reverseHead2 = reverseList2(deepCopy(head));
  printList(reverseHead2);

  // head 指向的值没有被修改
  printList(head);

  return 0;
}