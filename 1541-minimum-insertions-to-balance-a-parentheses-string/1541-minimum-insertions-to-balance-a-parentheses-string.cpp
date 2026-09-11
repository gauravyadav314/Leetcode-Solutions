class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        stack<char> st;
        int i=0;
        int n = s.size();
        while(i < n) {
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')') {
                if(st.empty()) {
                    if(i+1 < n && s[i+1]==')') {
                        count++;
                        i++;
                    }
                    else count+=2;
                }
                else if(i+1 < n && s[i+1]==')') {
                    st.pop();
                    i++;
                }
                else {
                    count++;
                    st.pop();
                }
            } 
            i++;
        }
        return count+(2*st.size());
    }
};