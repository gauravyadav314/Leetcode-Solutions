class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<bool> visited(2001, 0);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int l=i;
            int r=i;
            // odd palindrome
            bool found = false;
            while(l>=0 && !visited[l] && r<n && s[l]==s[r]) {
                int len = r-l+1;
                if(len == k) {
                    cout<<"o"<<i<<" "<<s.substr(l, len)<<endl;
                    cnt++;
                    visited[l] = 1;
                    visited[r] = 1;
                    break;
                }
                else if(len > k) {
                    cout<<"o"<<i<<" "<<s.substr(l, len)<<endl;
                    cnt++;
                    visited[l] = 1;
                    visited[r] = 1;
                    break;
                }
                l--;
                r++;
            }

            // even palindrome
            if(i < n-1) {
                l = i;
                r = i+1;
                while(l>=0 && !visited[l] && r<n && s[l]==s[r]) {
                    int len = r-l+1;
                    if(len == k) {
                        cout<<"e"<<i<<" "<<s.substr(l, len)<<endl;
                        cnt++;
                        visited[l] = 1;
                        visited[r] = 1;
                        i++;
                        break;
                    }
                    else if(len > k) {
                        cout<<"e"<<i<<" "<<s.substr(l, len)<<endl;
                        cnt++;
                        visited[l] = 1;
                        visited[r] = 1;
                        i++;
                        break;
                    }
                    l--;
                    r++;
                }
            }
        }
        return cnt;
    }
};