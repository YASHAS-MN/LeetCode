class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0, n = nums.size();
        int j=n-1, k=n-1;
        vector<int> res(n,0);

        while( i<=j ){
            if(abs(nums[i])>abs(nums[j])){
                res[k] = nums[i]*nums[i];
                i++;
            }else{
                res[k] = nums[j]*nums[j];
                j--;
            }
            k--;
        }
        return res;
    }
};