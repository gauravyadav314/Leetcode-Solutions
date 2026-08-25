class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        long long t = 1LL*target;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                int k=j+1;
                int l=n-1;
                while(k < l && k<n && l<n) {
                    long long sum = 1LL*(nums[i]+nums[j]);
                    sum += 1LL*nums[k];
                    sum += 1LL*nums[l];
                    if(sum == t) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k<l && k<n && nums[k] == nums[k-1]) k++;
                        while(k<l && l>=0 && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum > t) l--;
                    else k++;
                }
            }
        }
        
        
        return ans;
    }
};