class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int n = nums.size();

        for(int i=0; i<nums.size(); i++)
        n^=i^nums[i];
        return n;*/

        int n = nums.size();

        int expected = n*(n+1)/2;
        int actual = 0;

        for(int num : nums)
            actual+=num;

        return expected-actual;
    }
};