class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char, int> mp;
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j < n) {
            mp[s[j]]++;
            while(mp[s[j]] > 2) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            int len = j-i+1;
            maxLen = max(maxLen, len);
            j++;
        }
        return maxLen;
    }
};