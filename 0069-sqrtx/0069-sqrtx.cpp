class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        int j=x;
        int ans=-1;
        while(i<=j) {
            int mid = i+(j-i)/2;
            long long temp = 1LL*mid*mid;
            if(temp==x) return mid;
            else if(temp > x) {
                j = mid-1;
            }
            else i = mid+1;
        }
        return j;
        
    }
};