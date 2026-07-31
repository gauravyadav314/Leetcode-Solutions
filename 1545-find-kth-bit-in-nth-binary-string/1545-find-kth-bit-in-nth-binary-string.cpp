class Solution {
public:
    string comp_revese (string s) {
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='0') s[i] = '1';
            else s[i] = '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0; i<n; i++) {
            s = s+('1'+comp_revese(s));
        }
        return s[k-1];
    }
};