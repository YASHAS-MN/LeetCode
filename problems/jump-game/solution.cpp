class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, i;

        for(i=0; i<nums.size(); i++){
            if(i>farthest) 
                return false;
            else
                farthest = max(farthest, i+nums[i]);
        }
        return true;
    }
};