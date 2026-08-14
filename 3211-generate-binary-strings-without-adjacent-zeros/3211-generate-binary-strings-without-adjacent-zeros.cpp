class Solution {
public:
    void helper(int n, vector<string>& ans, string s, bool last) {
        if(s.size()==n) {
            ans.push_back(s);
            return;
        }
        if(last == true) helper(n, ans, s+'1', false);
        else {
            helper(n, ans, s+'0', true);
            helper(n, ans, s+'1', false);
        }
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, ans, "", false);
        return ans;
    }
};