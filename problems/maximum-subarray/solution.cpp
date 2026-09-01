class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int m = nums[0];
        int i;

        for(i=1;i<nums.size();i++){
            cur = max(nums[i], cur+nums[i]);
            m=max(m, cur);
        }
        return m;
    }
};