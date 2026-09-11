class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for(int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for(int num = 100; num <= 998; num += 2) {
            vector<int> req(10, 0);

            req[num % 10]++;
            req[(num / 10) % 10]++;
            req[num / 100]++;

            bool valid = true;

            for(int i = 0; i < 10; i++) {
                if(req[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ans++;
            }
        }

        return ans;
    }
};