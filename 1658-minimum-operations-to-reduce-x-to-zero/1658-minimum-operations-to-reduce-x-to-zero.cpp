class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0, k;
        int n = nums.size();
        for(int num : nums) {
            totalSum += num;
        }
        k = totalSum - x;
        if(k < 0) return -1;
        if(k == 0) return n;
        int i=0, j=0;
        int sum = 0;
        int maxLen = -1;
        while(j < n) {
            sum += nums[j];
            while(sum > k) sum -= nums[i++];

            if(sum == k) maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen != -1 ? n - maxLen : -1;
    }
};