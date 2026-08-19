class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int, vector<int>> mp;

        for (auto &x : r) {
            int row = x[0] - 1;
            int col = x[1] - 1;

            if (mp.find(row) == mp.end())
                mp[row] = vector<int>(10, 0);

            mp[row][col] = 1;
        }

        int ans = 2 * (n - mp.size());

        for (auto &it : mp) {
            vector<int>& seats = it.second;

            bool one = true, two = true, three = true;

            for (int j = 1; j <= 4; j++) {
                if (seats[j]) {
                    one = false;
                    break;
                }
            }

            for (int j = 3; j <= 6; j++) {
                if (seats[j]) {
                    two = false;
                    break;
                }
            }

            for (int j = 5; j <= 8; j++) {
                if (seats[j]) {
                    three = false;
                    break;
                }
            }

            if (one && two && three)
                ans += 2;
            else if (one || two || three)
                ans++;
        }

        return ans;
    }
};