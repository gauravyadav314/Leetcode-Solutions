class Solution {
public:
    int countCommas(int n) {
        string ans = to_string(n);
        int size = ans.size();
        if(size<=3) return 0;
        return n-1000+1;
    }
};