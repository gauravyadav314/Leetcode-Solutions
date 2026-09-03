class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool odd = false;
        int even = 0;
        bool ans = true;
        for(int& x : nums) {
            if(x%2 == 0 && !odd) {
                even++;
                ans = false;
            }
            else odd = true;
        }
        return (even == n)? true : ans;
    }
};