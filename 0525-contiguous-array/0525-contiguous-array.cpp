class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix += (nums[i] % 2 == 0) ? 1 : -1;

            if (mp.find(prefix) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefix]);
            } else {
                mp[prefix] = i;
            }
        }

        return maxLen;
    }
};