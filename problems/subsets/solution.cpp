class Solution {
private:
        vector<vector<int>> res;
public:
    void sol(vector<int>& nums, vector<int>& cur, int ind){
        if(ind == nums.size()){
         res.push_back(cur);
         return;
        }

        cur.push_back(nums[ind]);

        sol(nums, cur, ind+1);

        cur.pop_back();

        sol(nums, cur, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;

        sol(nums, cur, 0);

        return res;
    }
};