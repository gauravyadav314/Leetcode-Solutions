class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            int effort = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if(x == n-1 && y == m-1) return effort;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newEffort = max(effort,
                        abs(heights[x][y] - heights[nx][ny]));

                    if(newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};