/* Problem: Merge 2 Sorted Linked List
 * Using Priority Queue with specific comparison function
 *

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct compar {
        bool operator()(ListNode* p1, ListNode* p2) const {
            return p1->val > p2->val;
        }
    };
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        priority_queue<ListNode*, vector<ListNode*>, compar> q;
        q.push(l1), q.push(l2);
        ListNode* newlist = new ListNode(0), *curr = newlist;
        while(!q.empty()) {
            curr -> next = q.top();
            curr = curr -> next;
            q.pop();
            if(curr ->next) q.push(curr->next);
        }
        return newlist->next;
    }
};
