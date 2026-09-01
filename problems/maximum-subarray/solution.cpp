class Solution {
public:
    /*int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int m = nums[0];
        int i;

        for(i=1;i<nums.size();i++){
            cur = max(nums[i], cur+nums[i]);
            m=max(m, cur);
        }
        return m;
    }*/

    int cross(vector<int>& nums, int l, int m, int r){
        int s=0;
        int lm = INT_MIN;

        for(int i=m; i>=l; i--){
            s+=nums[i];
            lm=max(lm,s);
        }

        s=0;
        int rm = INT_MIN;

        for(int i=m+1;i<=r;i++){
            s+=nums[i];
            rm=max(rm, s);
        }
        return lm+rm;
    }

    int sol(vector<int>& nums, int l, int r){
        if(l==r)
         return nums[l];

        int m = l+(r-l)/2;

        int lb=sol(nums, l, m);
        int rb=sol(nums, m+1, r);
        int cb = cross(nums, l, m, r);

        return max(max(lb,rb),cb);
    }

    int maxSubArray(vector<int>& nums){
        return sol(nums, 0, nums.size()-1);
    }
};