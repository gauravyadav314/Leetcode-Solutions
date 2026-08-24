class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j]==0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto& it : row) {
            for(int i=0; i<c; i++) {
                matrix[it][i]=0;
            }
        }
        for(auto& it : col) {
            for(int i=0; i<r; i++) {
                matrix[i][it]=0;
            }
        }
    }
};