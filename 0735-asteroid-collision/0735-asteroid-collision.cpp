class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int val : asteroids) {
            if(val > 0) st.push_back(val);
            else {
                if(!st.empty() && st.back()>0 && st.back() > abs(val)) continue;
                while(!st.empty() && st.back()>0 && st.back() < abs(val)) st.pop_back();
                if(st.empty() || st.back() < 0) st.push_back(val);
                else if(st.back() == abs(val)) st.pop_back();
            }
        }
        return st;
    }
};