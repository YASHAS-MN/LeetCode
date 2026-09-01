class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /* this approach consumes O(n) space
        unordered_set<int> seen;

        for(int i : nums){
            if(seen.count(i))
             return i;

            seen.insert(i);
        }
        return -1;*/

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            }while(slow!=fast);

        slow = nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};