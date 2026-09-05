class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        for(int i=nums.size()-1; i>=0; i--)
            {
                if(mini > nums[i]) mini = nums[i];
                mp[i] = mini;
            }
        for(int i=0; i<nums.size(); i++)
            {
                if(maxi < nums[i]) maxi = nums[i];
                mini = mp[i];
                if((maxi-mini) <= k) return i;
            }
        return -1;
        
    }
};