class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int curSum=0, curMin=0, maxSum=INT_MIN;
        for(int i=0; i<n; i++) {
            curSum = max(curSum+nums[i], nums[i]);
            curMin = min(curMin+nums[i], nums[i]);
            maxSum = max(maxSum, max(curSum, abs(curMin)));
        }
        return maxSum;
    }
};