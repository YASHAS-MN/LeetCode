class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;

    void sol(vector<int>& nums, vector<int>& cur){
        if(cur.size() == nums.size())
         res.push_back(cur);

        for(int i=0; i<nums.size(); i++){
            if(used[i])
            continue;

            cur.push_back(nums[i]);
            used[i] = true;

            sol(nums, cur);

            used[i] = false;
            cur.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);

        vector<int> cur;

        sol(nums, cur);

        return res;
    }
};