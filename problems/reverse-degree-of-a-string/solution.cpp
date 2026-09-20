class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int i, pos, ans=0;

        for(i=0; i<n; i++){
            pos = 26 - (s[i] - 'a');
            ans+=pos*(i+1);
        }
    return ans;
    }
};