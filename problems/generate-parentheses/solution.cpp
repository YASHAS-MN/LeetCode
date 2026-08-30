class Solution {
private:
        vector<string> res;
public:
    void sol(string& cur, int o, int c, int n){
        if(cur.size() == 2*n){
            res.push_back(cur);
            return;
        }

        if(o<n){
            cur.push_back('(');
            sol(cur, o+1, c, n);
            cur.pop_back();
        }

        if(c<o){
            cur.push_back(')');
            sol(cur, o, c+1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        sol(cur, 0, 0, n);
        return res;
    }
};