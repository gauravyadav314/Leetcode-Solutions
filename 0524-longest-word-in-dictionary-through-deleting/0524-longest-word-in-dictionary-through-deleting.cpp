class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(string str : dictionary) {
            int i = 0;
            int j = 0;

            while(i < s.size() && j < str.size()) {
                if(s[i] == str[j]) {
                    j++;
                }
                i++;
            }

            if(j == str.size()) {
                if(str.size() > ans.size()) {
                    ans = str;
                }
                else if(str.size() == ans.size() && str < ans) {
                    ans = str;
                }
            }
        }

        return ans;
    }
};