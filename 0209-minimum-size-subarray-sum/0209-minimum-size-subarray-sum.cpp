class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int minLen = INT_MAX;
        long long sum = 0;
        while(j<n) {
            sum+= 1LL*nums[j];
            int len=0;
            if(sum >= target) {
                len = j-i+1;
                minLen = min(len, minLen);
                while(sum-nums[i] >= target && i<=j) {
                    sum-= nums[i];
                    i++;
                    len = j-i+1;
                    minLen = min(len, minLen);
                }  
            }
            j++;
        }
        return (minLen==INT_MAX)? 0 : minLen;
    }
};