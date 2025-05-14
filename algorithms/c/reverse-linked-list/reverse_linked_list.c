
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

static struct ListNode* createNode(int val) {
  struct ListNode* newnode = malloc(sizeof(struct ListNode));
  newnode->next = NULL;
  newnode->val = val;
  return newnode;
}

static void addAtHead(struct ListNode** head, int val) {
  struct ListNode* tmp = *head;
  struct ListNode* newnode = createNode(val);
  newnode->next = tmp;
  *head = newnode;
}

static struct ListNode* addAtHead2(struct ListNode* head, int val) {
  struct ListNode* tmp = head;
  struct ListNode* newnode = createNode(val);
  newnode->next = tmp;
  return newnode;
}

struct ListNode* reverseList(struct ListNode* head) {
  if (!head) return NULL;
  
  struct ListNode* current = head;
  struct ListNode* reverseHead = createNode(head->val);
  while(current->next) {
    addAtHead(&reverseHead, current->next->val);

    current = current->next;
  }

  return reverseHead;
}

static struct ListNode* createListNodes(int length) {

  struct ListNode* head = createNode(0);
  for (int i = 1; i < length; i++) {
    addAtHead(&head, i);
  }
  return head;
}

static void printList(struct ListNode* head) {
  if (head) {
    struct ListNode* current = head;
    while(current) {
      printf("%d-", current->val);
      current = current->next;
    }
  }
  printf("\n");  
}

static struct ListNode* reverseList2(struct ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  return NULL;
}

void changeHeadNext(struct ListNode* head) {
  head->next = NULL;
}

int main() {
  struct ListNode* head = createListNodes(5);
  head = addAtHead2(head, 5);
  changeHeadNext(head);
  printList(head);

  // struct ListNode* reverseHead = reverseList(head);
  // printList(reverseHead);

  return 0;
}