class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>mp;
        for(char ch : tasks) mp[ch]++;
        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty()) {
            vector<int> temp;
            int i=0;
            while(i < n+1 && !pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if(cnt) temp.push_back(cnt);
                time++;
                i++;
            }
            for(int x : temp) pq.push(x);
            if(pq.empty()) break;
            time += n+1-i;
        }
        return time;
    }
};