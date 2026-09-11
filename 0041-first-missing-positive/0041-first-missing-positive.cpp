class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = 0;
        unordered_set<int> st;
        for(int num : nums) {
            maxi = max(maxi, num);
            st.insert(num);
        }
        for(int i=1; i<=maxi; i++) {
            if(!st.contains(i)) return i;
        }
        return maxi+1;
    }
};