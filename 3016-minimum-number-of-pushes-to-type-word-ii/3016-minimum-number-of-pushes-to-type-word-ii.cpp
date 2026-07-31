class Solution {
public:
    int minimumPushes(string word) {
        vector <int> hash(26, 0);
        int n = word.size();
        for(int i=0; i<n; i++) {
            hash[word[i]-'a']++;
        }
        sort(hash.begin(), hash.end());
        int ans = 0;
        int count = 1;
        for(int i=25; i>=0; i--) {
            if(count >= 1 && count <= 8) {
                ans+=hash[i];
                count++;
            }
            else if(count >=9 && count <= 16) {
                ans+= 2*hash[i];
                count++;
            }
            else if(count >= 17 && count <= 24) {
                ans+=3*hash[i];
                count++;
            }
            else {
                ans+=4*hash[i];
                count++;
            }
        }
        return ans;
    }
};