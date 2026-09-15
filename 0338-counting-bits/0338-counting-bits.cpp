class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            int ones = 0;
            int x = i;
            while(x)
            {
                ones++;
                x = x&(x-1);
            }
            ans.push_back(ones);
        }
        return ans;
    }
};