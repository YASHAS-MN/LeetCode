class Solution {
private:
        vector<string> res;

        string letter[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
public:
    void sol(string& cur, string& dig, int ind){
            if(ind == dig.size()){
                res.push_back(cur);
                return;
            }
            
            int d = dig[ind] - '0';
            string choice = letter[d];

            for(int i=0; i<choice.size(); i++){
                cur.push_back(choice[i]);
                sol(cur, dig, ind+1);
                cur.pop_back();
            }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string cur;
        sol(cur, digits, 0);
        return res;
    }
};