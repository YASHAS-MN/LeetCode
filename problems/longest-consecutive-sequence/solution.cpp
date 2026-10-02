class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> g(nums.begin(), nums.end());
        int ans = 0;

        for(int i: g){
            if(g.find(i-1) == g.end()){
                int count = 1;
                int cur = i;

                while(g.find(cur+1) != g.end()){
                    count++;
                    cur++;
                }
                ans = max( ans, count );
            }
        }
        return ans;
    }
};