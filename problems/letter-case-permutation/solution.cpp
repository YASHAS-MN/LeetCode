class Solution {
public:
    vector<string> res;

    void sol(string& s, int ind){
        if(ind == s.length()){
            res.push_back(s);
            return;
        }

        if(isdigit(s[ind])){
            sol(s, ind+1);
            return;
        }

        s[ind] = tolower(s[ind]);
        sol(s, ind+1);

        s[ind] = toupper(s[ind]);
        sol(s, ind+1);
    }

    vector<string> letterCasePermutation(string s) {
        sol(s, 0);
        return res;
    }
};