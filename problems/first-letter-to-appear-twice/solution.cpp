class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> hs;

        for(char c : s){
            if(hs.count(c))
                return c;
            hs.insert(c);
        }
        return ' ';
    }
};