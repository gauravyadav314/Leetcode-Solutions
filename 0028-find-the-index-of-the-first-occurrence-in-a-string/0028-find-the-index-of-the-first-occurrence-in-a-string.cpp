class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle) return 0;
        int ind = -1;
        int h = haystack.size();
        int n = needle.size();
        int i=0;
        int k=0;
        int j=0;
        for(int i=0; i<h; i++) {
            if(haystack[i]==needle[j]) {
                ind = i;
                k=i;
                while(haystack[k]==needle[j] && j < n && k<h) {
                    k++;
                    j++;
                }
                if(j==n) return ind;
            }
            ind=-1;
            j=0;
        }
        return ind;
    }
};