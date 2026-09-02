class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) == mp.end()) {
                for (auto& pair : mp) {
                    if (pair.second == t[i]) {
                        return false;
                    }
                }
                mp[s[i]] = t[i];
            }
            else {
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};