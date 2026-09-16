class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        for(int i=0; i<r; i++) {
            if(board[i][0]=='O') {
                visited[i][0] = true;
                q.push({i, 0});
            }
            if(board[i][c-1]=='O') {
                visited[i][c-1] = true;
                q.push({i, c-1});
            }
        }
        for(int i=0; i<c; i++) {
            if(board[0][i]=='O') {
                visited[0][i] = true;
                q.push({0, i});
            }
            if(board[r-1][i]=='O') {
                visited[r-1][i] = true;
                q.push({r-1, i});
            }
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<r && ny>=0 && ny<c && board[nx][ny] == 'O' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j]=='O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};