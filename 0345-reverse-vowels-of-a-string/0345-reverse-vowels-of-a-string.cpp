class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while(i < j) {
            if(st.contains(s[i]) && st.contains(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!st.contains(s[i])) i++;
            else if(!st.contains(s[j])) j--;
        }
        return s;
    }
};