class Solution {
public:
    vector<int> row(int row) {
        vector<int> temp;
        temp.push_back(1);
        long long ans = 1;
        for(int i=1; i<row; i++) {
            ans *= (row-i);
            ans /= i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            vector<int> temp = row(i);
            ans.push_back(temp);
        }
        return ans;
    }
};