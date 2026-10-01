class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, char> m,n;

        for(int i=0;i<s.length(); i++){
            if(m.count(s[i]) && m[s[i]]!=t[i]) return false;
        
            if(n.count(t[i]) && n[t[i]]!=s[i]) return false;

            m[s[i]] = t[i];
            n[t[i]] = s[i];
        }
        return true;
    }
};