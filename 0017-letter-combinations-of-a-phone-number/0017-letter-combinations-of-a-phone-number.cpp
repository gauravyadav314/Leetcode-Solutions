class Solution {
public:
    void helper(string& d, unordered_map<char, string>& mp, vector<string>& ans, string s, int ind) {
        if(ind == d.size()) {
            ans.push_back(s);
            return;
        }
        int n = mp[d[ind]].size();
        for(int i=0; i<n; i++) {
            helper(d, mp, ans, s+=mp[d[ind]][i], ind+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        helper(digits, mp, ans, "", 0);
        return ans;
    }
};