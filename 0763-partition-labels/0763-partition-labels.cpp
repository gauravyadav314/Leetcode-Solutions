class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        int n = s.size();
        for(int i=0; i<n; i++) {
            mp[s[i]-'a'] = i;
        }
        int i=0;
        int j=0;
        int max_reach=0;
        vector<int> ans;
        while(j<n) {
            max_reach = max(max_reach, mp[s[j]-'a']);
            if(j == max_reach) {
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};