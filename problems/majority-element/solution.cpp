class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int count = 0;

        for(int i : nums){
            if(count == 0)
                cand = i;

            if(i == cand)
                count++;
            else
                count--;
        }
        return cand;
    }
};