class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int s =0;
        int m = INT_MAX;

        for(int r=0; r<nums.size(); r++){
            s+=nums[r];

            while(s>=target){
                m = min(m, r-l+1);

                s-=nums[l];
                l++;
            }
        }
        return m == INT_MAX?0:m;
    }
};