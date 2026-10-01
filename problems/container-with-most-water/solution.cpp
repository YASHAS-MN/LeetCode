class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, ans=0;

        while(i<j){
            int h = min(height[i], height[j]);
            int a = h * (j - i);

            ans = max ( ans, a );

            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};