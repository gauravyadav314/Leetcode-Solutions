class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x : stones) {
            pq.push(x);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            int y = pq.top();
            if(x > y) swap(x, y);
            pq.pop();
            if(x != y) {
                pq.push(y-x);
            }
        }
        return 0;
    }
};