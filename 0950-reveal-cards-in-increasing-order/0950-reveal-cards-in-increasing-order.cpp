class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        if(n <= 2) return deck;
        deque<int> q;
        for(int i=0; i<n; i++) {
            q.push_back(i);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            int ind = q.front();
            q.pop_front();
            ans[ind] = deck[i];
            if(!q.empty()) {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        return ans;
    }
};