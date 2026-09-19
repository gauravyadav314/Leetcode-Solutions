class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(n, {0,0}));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                path[i][j] = {i, j};
            }
        }
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        queue<vector<int>> q;
        q.push({0, 0, 0});
        dist[0][0] = 0;
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int dis = q.front()[2];
            q.pop();
            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny]==0) {
                    if(dist[nx][ny] > dis + 1) {
                        dist[nx][ny] = dis + 1;
                        q.push({nx, ny, dis+1});
                        path[nx][ny] = {x, y};
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        int x = n-1;
        int y = n-1;
        int cnt = 0;
        while(x != 0 || y != 0) {
            cnt++;
            auto temp = path[x][y];
            x = temp.first;
            y = temp.second; 
        }
        return cnt+1;

    }
};