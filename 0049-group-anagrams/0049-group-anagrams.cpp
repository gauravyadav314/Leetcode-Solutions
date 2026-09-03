class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        for(int i=0; i<n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        for(auto& it : mp) {
            vector<int> temp = it.second;
            int len = it.second.size();
            vector<string> cur;
            for(int i=0; i<len; i++) {
                cur.push_back(strs[temp[i]]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};