class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(char a : jewels) st.insert(a);
        int n = stones.size();
        int count = 0;
        for(char a : stones) {
            if(st.find(a) != st.end()) {
                count++;
            }
        }
        return count;
    }
};