class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const long long MOD = 1000000007;
        int n = arr.size();

        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        // Kadane on at most 2 copies
        long long curr = 0;
        long long maxSum = 0;

        int limit = (k == 1 ? n : 2 * n);

        for (int i = 0; i < limit; i++) {
            curr = max(0LL, curr + arr[i % n]);
            maxSum = max(maxSum, curr);
        }

        // Extra copies help only when total sum is positive
        if (k > 2 && totalSum > 0) {
            maxSum += totalSum * (k - 2);
        }

        return maxSum % MOD;
    }
};