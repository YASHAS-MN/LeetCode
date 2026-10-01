class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> k;

        for(char c: m) k[c]++;

        for(char c: r){
            k[c]--;
            if(k[c]<0) return false;
        }
        return true;
    }
};