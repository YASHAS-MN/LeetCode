class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> ans(numRows+1, 1);

        for(int i=0; i<numRows; i++){
            for(int j=i; j>0; j--){
                ans[j]+=ans[j-1];
            }
        }
        return ans;
    }
};