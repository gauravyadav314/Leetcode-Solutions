class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        unordered_map<int, int> mp;
        long long sum = 0;
        long long maxSum = 0;
        while(j< n) {
            while(mp.find(nums[j]) != mp.end()) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            mp[nums[j]]++;
            sum += 1LL*nums[j];
            if(j-i+1 == k) {
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxSum;
    }
};