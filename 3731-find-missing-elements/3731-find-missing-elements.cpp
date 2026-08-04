class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++)
            {
                maxi = max(nums[i], maxi);
                mini = min(nums[i], mini);
            }
        unordered_map<int, int> mp;
        for(auto& i : nums) mp[i] = i;
        vector<int> ans;
        for(int i=mini+1; i<maxi; i++)
            {
                if(mp.find(i) == mp.end()) ans.push_back(i);
            }
        sort(ans.begin(), ans.end());
        return ans;
    }
};