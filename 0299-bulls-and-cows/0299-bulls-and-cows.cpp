class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char, int>mp;
        for(char ch : s) mp[ch]++;
        int n = g.size();
        int i=0;
        int A = 0;
        int B = 0;
        while(i < n) {
            if(s[i]==g[i]) {
                A++;
                mp[g[i]]--;
                if(mp[g[i]]==0) mp.erase(g[i]);
            }
            i++;
        }
        i = 0;
        while(i < n) {
            if(g[i] != s[i] && mp.find(g[i]) != mp.end()) {
                    B++;
                    mp[g[i]]--;
                    if(mp[g[i]]==0) mp.erase(g[i]);
                }
                i++;
        }
        string ans = to_string(A)+'A'+to_string(B)+'B';
        return ans;
    }
};