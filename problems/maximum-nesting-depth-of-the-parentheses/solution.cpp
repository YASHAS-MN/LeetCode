class Solution {
public:
    int maxDepth(string s) {
        int x=0, ans=0;

        for(auto &i : s){
            if(i == '(' ) x++;
            if( i == ')' ) x--;
            ans = max(ans, x);
        }
        return ans;
    }
};