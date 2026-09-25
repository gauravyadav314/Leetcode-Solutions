class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp(n);

        int mid = (n - 1) / 2;
        int high = n - 1;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                temp[i] = nums[mid--];
            }
            else {
                temp[i] = nums[high--];
            }
        }

        nums = temp;
    }
};