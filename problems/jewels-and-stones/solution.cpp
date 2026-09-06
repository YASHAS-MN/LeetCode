class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        /*bool is[128] = {false};

        for(char j : jewels)
            is[j] = true;

        int c = 0;

        for(char s : stones){
            if(is[s])
                c++;
        }
        return c++;*/

        unordered_set<char> hs;

        for(char j : jewels)
            hs.insert(j);

        int c = 0;

        for(char s : stones){
            if(hs.count(s))
                c++;
        }
        return c;
    }
};