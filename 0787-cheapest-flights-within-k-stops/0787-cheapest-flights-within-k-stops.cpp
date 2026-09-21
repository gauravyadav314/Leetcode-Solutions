class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto ad : adj[node]) {
                if(ad.second + dis < dist[ad.first] && stops <= k) {
                    dist[ad.first] = dis + ad.second;
                    q.push({stops+1, {ad.first, ad.second+dis}});
                }
            }
        }
        return dist[dst]==1e9? -1 : dist[dst];
    }
};