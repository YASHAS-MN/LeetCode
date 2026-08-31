class Solution {
private:
        vector<vector<int>> res;
public:

    void sol(vector<int>& nums, int st, vector<int>& cur){
        res.push_back(cur);

        for(int i=st; i<nums.size(); i++){
            if(i>st && nums[i] == nums[i-1])
             continue;
            
            cur.push_back(nums[i]);
            sol(nums, i+1, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        sol(nums, 0, cur);
        return res;
    }
};