class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> prevSm(n, 0);
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            prevSm[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        vector<int> nextSm(n, 0);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nextSm[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        vector<int> prevGm(n, 0);
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            prevGm[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        vector<int> nextGm(n, 0);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nextGm[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long minSum = 0;
        for(int i=0; i<n; i++) {
            int prev = i-prevSm[i];
            int next = nextSm[i]-i;
            minSum += (1LL*nums[i]*prev*next);
        }
        long long maxSum = 0;
        for(int i=0; i<n; i++) {
            int prev = i-prevGm[i];
            int next = nextGm[i]-i;
            maxSum += (1LL*nums[i]*prev*next);
        }
        return maxSum-minSum;
    }
};