class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1==version2) return 0;
        int n1 = version1.size();
        int n2 = version2.size();
        int i=0;
        int j=0;
        while(i<n1 || j<n2) {
            long long vOne=0, vTwo=0;
            while(i<n1 && version1[i] != '.') {
                vOne = vOne*10+(version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j] != '.') {
                vTwo = vTwo*10+(version2[j]-'0');
                j++;
            }
            if(vOne > vTwo) return 1;
            else if(vOne < vTwo) return -1;
            if(i<n1) i++;
            if(j<n2) j++;
        }
        return 0;
    }
};