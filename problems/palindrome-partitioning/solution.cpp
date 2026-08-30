class Solution {
public:
    vector<vector<string>> res;

    bool pal(string& word, int l, int r){
        while(l<r){
            if(word[l] != word[r])
             return false;

             l++; r--;
        }
        return true;
    }

    void sol(string& s, int st, vector<string>& cur){
        if(st == s.length()){
            res.push_back(cur);
            return;
        }

        for(int i=st; i<s.length(); i++){
            if(pal(s, st, i)){
                cur.push_back(s.substr(st, i-st+1));
                sol(s, i+1, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
                vector<string> cur;
                sol(s, 0, cur);
                return res;
    }
};