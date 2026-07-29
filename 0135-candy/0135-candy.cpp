class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i=1;
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {
                i++;
                continue;
            }
            int increasing = 0;
            while(i<n && ratings[i] > ratings[i-1]) {
                increasing++;
                candy += increasing;
                i++;
            }
            int decreasing = 0;
            while(i<n && ratings[i] < ratings[i-1]) {
                decreasing++;
                candy += decreasing;
                i++;
            }
            candy -= min(increasing, decreasing);
        }

        return candy;
    }
};