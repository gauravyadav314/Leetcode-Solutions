class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int fOdd = 1e9;
        int fEven = 1e9;
        int even = 0;
        int odd = 0;
        for(int& x : nums) {
            if(x%2 == 0) {
                even++;
                fEven = min(fEven, x);
            }
            else {
                odd++;
                fOdd = min(fOdd, x);
            }
        }
        if(odd == n || even == n) return true;
        return (fOdd < fEven);
    }
};