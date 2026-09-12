class Solution {
public:
    bool possible(string& s, string& p, vector<int>& r, int k) {
        vector<bool> removed(s.size(), false);
        for (int i = 0; i < k; i++) {
            removed[r[i]] = true;
        }

        int j = 0; // Pointer for p
        for (int i = 0; i < (int)s.size() && j < (int)p.size(); i++) {
            if (!removed[i] && s[i] == p[j]) {
                j++;
            }
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int low = 0;
        int high = n;
        int ans = 0;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(possible(s, p, removable, mid)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};