class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxInd = -1;
        int minInd = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]<mini)
            {
                mini = nums[i];
                minInd = i;
            }
            if(nums[i]>maxi)
            {
                maxi = nums[i];
                maxInd = i;
            }
        }
        int front = min(maxInd, minInd);
        int last = max(maxInd, minInd);
        int a = front+1+(n-last);
        int b = n-front;
        int c = last+1;
        a = min(a, b);
        c = min(b, c);
        return min(a, c);
    }
};