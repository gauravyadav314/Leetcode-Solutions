class Solution {
private:
    bool bfs(int V, vector<vector<int>>& adj, vector<int>& visited, int& count) {
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(visited[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(auto adjacentNode : adj[node]) {
                visited[adjacentNode]--;

                if(visited[adjacentNode] == 0) {
                    q.push(adjacentNode);
                }
            }
        }

        return count == V;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];

            adj[b].push_back(a);
            visited[a]++;
        }

        int count = 0;

        return bfs(numCourses, adj, visited, count);
    }
};