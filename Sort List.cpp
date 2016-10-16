/*
 * Problem: Sort Linkedlist
 */

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

// Merge Sort
class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0), *tmp = head;
        while(l1 || l2) {
            if(!l2 || (l1 && l1->val < l2->val)) {
                tmp -> next = l1;
                l1 = l1 -> next;
            } else {
                tmp -> next = l2;
                l2 = l2 -> next;
            }
            tmp = tmp -> next;
        }
        return head -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head, *fast = head, *prev;
        while(fast && fast->next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* tmp = slow -> next;
        prev -> next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }
};
