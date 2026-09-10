class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : mp) {
            pq.push({it.second, -it.first});
        }
        vector<int> ans;
        while(!pq.empty()) {
            pair<int, int> temp = pq.top();
            while(temp.first) {
                ans.push_back(-temp.second);
                temp.first--;
            }
            pq.pop();
        }
        return ans;
    }
};