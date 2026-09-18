class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        int i = 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) if(!indegree[i]) q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int a : adj[node]) {
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};