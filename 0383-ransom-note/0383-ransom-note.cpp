class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char ch : magazine) mp[ch]++;
        int n = ransomNote.size();
        for(char ch : ransomNote) {
            if(mp.find(ch) == mp.end()) return false;
            mp[ch]--;
            if(mp[ch]==0) mp.erase(ch);
        }
        return true;
    }
};