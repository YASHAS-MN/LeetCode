class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;

            for(int i: arr1){
                string x = to_string(i);

                for(int j: arr2){
                    string y = to_string(j);
                    int c = 0;

                    while(c<x.size() && c<y.size() && x[c]==y[c])
                        c++;
                ans = max(ans, c);
                }
            }
    return ans;
    }
};