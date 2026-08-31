class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int cur = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)
                cur++;
            else
                cur=0;
            m = max(m, cur);
        }
        return m;
    }
};