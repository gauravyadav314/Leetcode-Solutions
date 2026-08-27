class Solution {
public:

    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0;
        string ans = "";
        while(i<n) {
            char t = chars[i];
            int j=i+1;
            int count=1;
            while(j<n && chars[j] == chars[i]) {
                count++;
                j++;
            }
            if(count==1) ans += t;
            else ans += t+to_string(count);
            i = j;
        }
        vector<char> a;
        for(int i=0; i<ans.size(); i++) a.push_back(ans[i]);
        chars = a;
        return ans.size();
    }
};