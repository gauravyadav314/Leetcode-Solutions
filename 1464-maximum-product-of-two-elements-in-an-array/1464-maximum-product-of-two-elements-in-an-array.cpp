class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int secondMax = INT_MIN;
        for(int& x : nums) {
            if(maxi >= x) {
                secondMax = max(secondMax, x);
            }
            if(maxi < x){
                secondMax = maxi;
                maxi = x;
            }
        }
        return (maxi-1)*(secondMax-1);
    }
};