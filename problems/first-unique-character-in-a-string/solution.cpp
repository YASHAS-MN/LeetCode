class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hs;

        for(char c : s)
            hs[c]++;

        for(int i=0; i<s.length(); i++){
            if(hs[s[i]] == 1)
                return i;
        }
        return -1;
    }
};