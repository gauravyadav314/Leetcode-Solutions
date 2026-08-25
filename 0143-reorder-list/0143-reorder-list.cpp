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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode dummy(0);
        ListNode* second = &dummy;
        second->next = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = second->next;
        while(cur) {
            ListNode* front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        second->next = prev;
        cur = head;
        ListNode* temp = second->next;
        while(cur && temp) {
            ListNode* curFront = cur->next;
            cur->next = temp;
            cur = curFront;
            ListNode* tempFront = temp->next;
            temp->next = cur;
            temp = tempFront;
        }
    }
};