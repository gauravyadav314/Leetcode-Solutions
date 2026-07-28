class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> leftCount;
        int preCandy = 1;
        int n=ratings.size();
        leftCount.push_back(1);
        for(int i=1; i<n; i++) {
            if(ratings[i]>ratings[i-1]) {
                int candyGiven = preCandy + 1;
                leftCount.push_back(candyGiven);
                preCandy = candyGiven;
            }
            else {
                leftCount.push_back(1);
                preCandy = 1;
            }
        }
        vector<int> rightCount;
        preCandy = 1;
        rightCount.push_back(1);
        for(int i=n-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {
                int candy = preCandy + 1;
                rightCount.push_back(candy);
                preCandy = candy;
            }
            else {
                rightCount.push_back(1);
                preCandy = 1;
            }
        }
        reverse(rightCount.begin(), rightCount.end());
        int count = 0;
        for(int i=0; i<n; i++) {
            count += max(leftCount[i], rightCount[i]); 
        }

        return count;
    }
};