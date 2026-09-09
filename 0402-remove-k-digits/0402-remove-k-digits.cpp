class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n = num.size();
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.back() > num[i] && k>0) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k--) st.pop_back();
        int i=0;
        while(i < st.size() && st[i] == '0') i++;
        return (st.substr(i).empty())? "0" : st.substr(i);
    }
};