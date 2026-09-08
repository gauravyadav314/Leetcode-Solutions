class Solution {
public:
    bool palindrome(string s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            string ans = "";
            for(int j=i; j<n; j++) {
                ans += s[j];
                if(palindrome(ans)) count++;
            }
        }
        return count;
    }
};