#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rev(string& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    int reverse(int x) {
        string s = to_string(x);
        rev(s);
        long long ans = x<0? -stoll(s) : stoll(s);
        if(ans>INT_MAX || ans < INT_MIN) return 0;
        return ans;
        
    }
};