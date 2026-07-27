class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int secondMax = INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++) {
            if(maxi >= nums[i]) {
                secondMax = max(secondMax, nums[i]);
            }
            if(maxi < nums[i]){
                secondMax = maxi;
                maxi = nums[i];
            }
        }
        return (maxi-1)*(secondMax-1);
    }
};