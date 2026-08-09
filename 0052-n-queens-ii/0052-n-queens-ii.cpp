class Solution {
public:
    bool safe(vector<string>& board, int row, int col) {
        for(int i=0; i<row; i++) if(board[i][col] == 'Q') return false;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++) 
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void helper(vector<string>& board, int& count, int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        for(int i=0; i<n; i++) {
            if(safe(board, row, i)) {
                board[row][i] = 'Q';
                helper(board, count, row+1, n);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        helper(board, count, 0, n);
        return count;
    }
};