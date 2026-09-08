class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26, 0);
        for(char ch : magazine) mp[ch-'a']++;
        int n = ransomNote.size();
        for(char ch : ransomNote) {
            if(mp[ch-'a'] == 0) return false;
            mp[ch-'a']--;
        }
        return true;
    }
};