class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gInd = 0;
        int sInd = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(gInd < g.size() && sInd < s.size()) {
            if(g[gInd] <= s[sInd]) gInd++;
            sInd++;
        }
        return gInd;
    }
};