class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        int mod = (int)1e9 + 7;

        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        pq.push({0, 0});

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adW = it.second;

                long long newDis = dis + adW;

                if(newDis < dist[adjNode]) {
                    dist[adjNode] = newDis;
                    ways[adjNode] = ways[node];
                    pq.push({newDis, adjNode});
                }
                else if(dist[adjNode] == newDis) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};