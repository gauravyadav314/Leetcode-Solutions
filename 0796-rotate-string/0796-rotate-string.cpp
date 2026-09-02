class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.size();

        if (n != goal.size())
            return false;

        // Check every possible starting position
        for (int start = 0; start < n; start++) {

            bool found = true;

            for (int j = 0; j < n; j++) {

                // Simulates (s + s)[start + j]
                if (s[(start + j) % n] != goal[j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return true;
        }

        return false;
    }
};