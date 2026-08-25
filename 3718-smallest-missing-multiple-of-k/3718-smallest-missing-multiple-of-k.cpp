class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& i : nums) mp[i]++;
        for(int i=1; i<=nums.size()+1; i++)
        {
            if(mp.find(i*k) == mp.end()) return k*i;
        }
        return -1;
    }
};