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
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         ListNode* temp = head;
//         if(temp->next->next==nullptr) return {-1, -1};
//         vector<int> nums;
//         while(temp) {
//             nums.push_back(temp->val);
//             temp = temp->next;
//         }
//         int n = nums.size();
//         int maxi=INT_MIN;
//         int mini=INT_MAX;
//         bool check = false;
//         int first = -1;
//         int prev = -1;
//         int count = 0;

//         for(int i=1; i<n-1; i++) {
//             if(nums[i]>nums[i-1] && nums[i]>nums[i+1] || nums[i]<nums[i-1] && nums[i]<nums[i+1]) {
//                 if(!check) {
//                     first = i;
//                     prev = -1e9;
//                     check = true;
//                 }
//                 if(check) {
//                     maxi = max(maxi, i-first);
//                     mini = min(mini, i-prev);
//                     prev = i;
//                 }
//                 count++;

//             }
            

//         }
//         if(count <= 1) return {-1, -1};
//         if(count == 2) return {maxi, maxi};
//         return {mini, maxi};
//     }
// };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        if(temp->next->next==nullptr) return {-1, -1};
        ListNode* pervPointer = temp;
        temp = temp->next;
        ListNode* front = temp->next;
        int ind = 0;
        bool check = 0;
        int first = 0;
        int prev = -1e9;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int count = 0;
        while(front) {
            ind++;
            if(pervPointer->val < temp->val && front->val < temp->val || pervPointer->val > temp->val && front->val > temp->val) {
                if(!check) {
                    first = ind;
                    check = true;
                }
                if(check) {
                    maxi = max(maxi, ind-first);
                    mini = min(mini, ind-prev);
                    prev = ind;
                }
                count++;
            }
            pervPointer = temp;
            temp = front;
            front = front->next;

        }
        if(count <= 1) return {-1, -1};
        if(count == 2) return {maxi, maxi};
        return {mini, maxi};
    }
};