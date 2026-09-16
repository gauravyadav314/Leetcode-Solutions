class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        for(int i=0; i<r; i++) {
            if(grid[i][0]==1) {
                q.push({i, 0});
                visited[i][0]=true;
            }
            if(grid[i][c-1]==1) {
                q.push({i, c-1});
                visited[i][c-1]=true;
            }
        }
        for(int i=0; i<c; i++) {
            if(grid[0][i]==1) {
                q.push({0, i});
                visited[0][i]=true;
            }
            if(grid[r-1][i]==1) {
                q.push({r-1, i});
                visited[r-1][i]=true;
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
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny]==1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j]==1 && !visited[i][j]) cnt++;
            }
        }
        return cnt;
    }
};