class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        long long mini = INT_MAX;
        long long t = 1LL*target;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int j=i+1;
            int k=n-1;
            while(j < k) {
                long long sum = 1LL*(nums[i]+nums[j]+nums[k]);
                if(sum > t) {
                    k--;
                    if(mini > sum-t) {
                        mini = sum-t;
                        ans = sum;
                    }
                }
                else if(sum < t) {
                    j++;
                    if(mini > t-sum) {
                        mini = t-sum;
                        ans = sum;
                    }
                }
                else {
                    return sum;
                    k--;
                    j++;
                }
            }
        }
        return (int)ans;
    }
};