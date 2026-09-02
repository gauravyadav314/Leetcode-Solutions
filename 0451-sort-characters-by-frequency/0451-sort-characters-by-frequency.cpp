class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v;
        unordered_map<char, int> mp;

        for(char& ch : s) 
            mp[ch]++;

        for(auto& it : mp) 
            v.push_back(it);

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for(auto& it : v) {
            for(int i = 0; i < it.second; i++) {
                ans += it.first;
            }
        }

        return ans;
    }
};