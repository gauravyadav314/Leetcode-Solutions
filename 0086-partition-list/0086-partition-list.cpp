/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        ListNode last(0);
        
        ListNode* dt = &dummy;
        ListNode* lt = &last;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val >= x) {
                lt->next = cur;
                lt = lt->next;
            } else {
                dt->next = cur;
                dt = dt->next;
            }
            cur = cur->next;
        }

        lt->next = nullptr; 
        dt->next = last.next;
        return dummy.next;
    }
};