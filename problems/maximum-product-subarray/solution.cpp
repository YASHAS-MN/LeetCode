class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int cmax=nums[0];
       int cmin=nums[0];
       int ans=nums[0];

       for(int i=1; i<nums.size(); i++){
        int x=nums[i];
        int omin=cmin;
        int omax=cmax;

        cmax=max({x, x*omax, x*omin});
        cmin=min({x, x*omax, x*omin});

        ans=max(ans, cmax);
       }
       return ans;
    }
};