class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n=nums.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right < n) {
            mp[nums[right]]++;
            if(mp[nums[right]] > k) {
                while(mp[nums[right]] > k && left<=right) {
                    mp[nums[left]]--;
                    left++;
                    if(mp[nums[left]]==0) mp.erase(nums[left]);
                }
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};