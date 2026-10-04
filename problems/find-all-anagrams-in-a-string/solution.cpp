class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int m=s.length(), n=p.length();
        vector<int> need(26,0), win(26,0);

        if(n>m) return ans;

        for(int i=0; i<n; i++){
            need[p[i] - 'a']++;
            win[s[i] - 'a']++;
        }

        for(int i=0; i<=m-n; i++){
            if(need==win)
                ans.push_back(i);

            if(i+n<m){
                win[s[i]-'a']--;
                win[s[i+n]-'a']++;
            }
        }
        return ans;
    }
};