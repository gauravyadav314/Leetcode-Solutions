class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> mini(n);
        int temp = INT_MAX;
        for(int i=n-1; i>=0; i--) {
            temp = min(nums[i], temp);
            mini[i] = temp;
        }
        for(int i=0; i<n; i++) {
            maxi = max(maxi, nums[i]);
            int temp = maxi-mini[i];
            if(temp <= k) {
                return i;
            }
        }
        return -1;
    }
};