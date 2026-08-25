class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        for(int i=0; i<n; i++) {
            // odd palindrome
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]) {
                int len = r-l+1;
                if(maxLen < len) {
                    start = l;
                    maxLen = len;
                }
                l--;
                r++;
            }

            // even palindrome
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                int len = r-l+1;
                if(maxLen < len) {
                    start = l;
                    maxLen = len;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};