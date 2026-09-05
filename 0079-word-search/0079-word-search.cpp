class Solution {
public:
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int ind) {
        if(ind == w.size()) return true;
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || w[ind] != b[i][j]) return false;
        char mark = b[i][j];
        b[i][j] = '@';
        bool found = {
            dfs(b, w, i+1, j, ind+1) ||
            dfs(b, w, i-1, j, ind+1) ||
            dfs(b, w, i, j+1, ind+1) ||
            dfs(b, w, i, j-1, ind+1)
        };
        b[i][j] = mark;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};