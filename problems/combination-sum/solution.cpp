class Solution {
public:
    vector<vector<int>> res;

    void sol(vector<int>& candidates, vector<int>& cur, int start, int target){
            if(target == 0){
                res.push_back(cur);
                return;
            }

            for(int i=start; i<candidates.size(); i++){
                if(candidates[i]>target)
                    continue;
                
                cur.push_back(candidates[i]);
                sol(candidates, cur, i, target - candidates[i]);
                cur.pop_back();
            }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        sol(candidates, cur, 0, target);
        return res;
    }
};