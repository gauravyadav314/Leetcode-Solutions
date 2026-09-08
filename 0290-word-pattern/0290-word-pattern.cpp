class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mp;
        unordered_map<char, string> mpp;
        int n = s.size();
        int i=0;
        int j=0;
        while(i < n) {
            string ans = "";
            while(i < n && s[i] != ' ') {
                ans+=s[i];
                i++;
            } 
            i++;
            if(mpp.find(pattern[j]) != mpp.end()) {
                if(mpp[pattern[j]] != ans) return false;
            }
            if(mp.find(ans) != mp.end()) {
                if(mp[ans] != pattern[j]) return false;
            }
            mp[ans] = pattern[j];
            mpp[pattern[j]] = ans;
            j++;
        }
        return j==pattern.size();

    }
};