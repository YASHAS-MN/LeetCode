class Solution {
public:
    vector<vector<int>> res;

    void sol(int n, int k, int s, vector<int>& cur){
            if(cur.size() == k){
                res.push_back(cur);
                return;
            }

            for(int i=s; i<=n; i++){
                cur.push_back(i);
                sol(n, k, i+1, cur);
                cur.pop_back();
            }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        sol(n, k, 1, cur);
        return res;
    }
};