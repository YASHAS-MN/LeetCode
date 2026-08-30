class Solution {
private:
        vector<vector<int>> res;
public:
    void sol(vector<int>& candidates, vector<int>& cur, int s, int k){
            if(k == 0){
                res.push_back(cur);
                return;
            }

            for(int i=s; i<candidates.size(); i++){
                if(i>s && candidates[i] == candidates[i-1])
                 continue;

                if(candidates[i]>k)
                 break;

                cur.push_back(candidates[i]);
                sol(candidates, cur, i+1, k-candidates[i]);
                cur.pop_back();
            }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        sol(candidates, cur, 0, target);
        return res;
    }
};