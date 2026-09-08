class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || numRows == n) return s;
        vector<string> temp(numRows, string(n, ' '));
        int ind = 0;
        int col = 0;
        while(ind < n) {
            for(int i=0; i<numRows && ind < n; i++) {
                temp[i][col] = s[ind];
                ind++;
            }
            if(ind >= n) break;
            col++;
            for(int i = numRows-2; i>0 && ind < n; i--) {
                temp[i][col] = s[ind];
                ind++;
                col++;
            }
            col++;
        }
        string ans = "";
        int c = temp[0].size();
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<c; j++) {
                if(temp[i][j] != ' ') ans+= temp[i][j];
            }
        }
        return ans;
    }
};