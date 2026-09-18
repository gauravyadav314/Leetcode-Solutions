class Solution {
public:
    vector<int> bfs(int V, vector<vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        int cnt = 0;
        for(int i=0; i<V; i++) if(indegree[i]==0) q.push(i);
        cnt = 0;
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            cnt++;
            for(auto a : adj[node]) {
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        if(cnt == V) return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        return bfs(numCourses, adj, indegree);
    }
};