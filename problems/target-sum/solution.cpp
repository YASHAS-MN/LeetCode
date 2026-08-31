class Solution {
public:
    int sol(vector<int>& nums, int i, int c, int k){
        if(i == nums.size()){
            if(c == k)
             return 1;
              return 0;
        }

        int add = sol(nums, i+1, c+nums[i], k);
        int sub = sol(nums, i+1, c-nums[i], k);

        return add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       return sol(nums, 0, 0, target);
    }
};