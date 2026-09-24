class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i == digitSum(nums[i])) {
                mini = min(mini, i);
            }
        }
        return mini==INT_MAX ? -1 : mini;
    }
};