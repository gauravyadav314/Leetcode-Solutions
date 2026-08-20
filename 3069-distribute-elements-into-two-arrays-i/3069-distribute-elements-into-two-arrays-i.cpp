class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        int n = nums.size();
        for(int i=2; i<n; i++) {
            if(a.back() > b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        int stop = b.size();
        for(int i=0; i<stop; i++) a.push_back(b[i]);
        return a;
    }
};