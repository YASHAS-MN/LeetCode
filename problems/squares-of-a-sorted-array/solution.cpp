class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*int i=0, n = nums.size();
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
        return res;*/
        int n = nums.size();
        vector<int> res(n,0);
        int left=0, right=n-1;

        for(int i=n-1; i>=0; i--){
            if(abs(nums[left])<abs(nums[right])){
                res[i]=nums[right]*nums[right];
                right--;
            }else{
                res[i]=nums[left]*nums[left];
                left++;
            }
        }
        return res;
    }
};