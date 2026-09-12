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
bool compareNodes(const ListNode* a, const ListNode* b) {
    return a->val > b->val; 
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compareNodes)> pq(compareNodes);

        for (auto it : lists) {
            if (it) {
                pq.push(it);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();

            cur = cur->next;

            if (cur->next) {
                pq.push(cur->next);
            }
        }

        return dummy->next;
    }
};