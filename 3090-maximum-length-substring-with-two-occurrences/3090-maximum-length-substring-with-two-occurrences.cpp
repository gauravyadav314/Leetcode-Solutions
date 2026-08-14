class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int mp[26];
        for(int i=0; i<26; i++) mp[i]=0;
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j < n) {
            mp[s[j]-'a']++;
            while(mp[s[j]-'a'] > 2) {
                mp[s[i]-'a']--;
                i++;
            }
            int len = j-i+1;
            maxLen = max(maxLen, len);
            j++;
        }
        return maxLen;
    }
};