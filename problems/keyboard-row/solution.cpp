class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> map;

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(char c : row1 ) map[c] = 1;
        for(char c : row2 ) map[c] = 2;
        for(char c : row3 ) map[c] = 3;

        vector<string> res;

        for(string& w : words)
        {
            if(w.empty()) continue;

            int tar = map[tolower(w[0])];
            bool isValid = true;

            for(char c : w)
            {
                if(map[tolower(c)] != tar)
                {
                    isValid = false;
                    break;
                }
            }

            if(isValid)
            res.push_back(w);
        }
        return res;
    }
};