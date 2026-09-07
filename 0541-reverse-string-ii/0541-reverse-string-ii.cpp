class Solution {
public:
    void rev(string& s, int st, int end) {
        while(st < end) {
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;

        while(i < n) {
            int j = i + 2 * k - 1;

            if(j >= n) {
                int end = min(i + k - 1, n - 1);
                rev(s, i, end);
                return s;
            }

            rev(s, i, i + k - 1);

            i = j + 1;
        }

        return s;
    }
};