class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;
        n = n-8;
        int ans = 8;
        for(int i=0; i<n && i<8; i++) ans+=2;
        n = n-8;
        if(n<=0) return ans;
        for(int i=0; i<n && i<8; i++) ans+=3;
        n = n-8;
        if(n<=0) return ans;
        ans+=4;
        n--;
        if(n<=0) return ans;
        ans+=4;
        return ans;
    }
};