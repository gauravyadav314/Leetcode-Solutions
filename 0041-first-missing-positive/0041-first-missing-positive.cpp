class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long maxi = 0;
        for(int num : nums) {
            maxi = max(maxi, 1LL*num);
        }
        vector<bool> st(maxi+1, 0);
        for(int num : nums) {
            if(num>0) st[num]=1;
        }
        for(int i=1; i<=maxi; i++) {
            if(!st[i]) return i;
        }
        return maxi+1;
    }
};