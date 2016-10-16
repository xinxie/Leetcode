/* Problem: Swap Nodes in Pairs
 * Extra level of indirection in C++. Unifying Code
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** addr = &head, *nextnode;
        while((*addr) && (nextnode = (*addr) -> next)) {
            (*addr) -> next = nextnode -> next;
            nextnode -> next = (*addr);
            (*addr) = nextnode;
            addr = &(nextnode->next->next);
        }
        return head;
    }
};
