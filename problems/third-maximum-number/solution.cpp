class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long f = LLONG_MIN;
        long long s = LLONG_MIN;;
        long long t = LLONG_MIN;

        for(int i : nums){
            if(i == f || i == s || i == t)
                continue;
            
            if(i > f){
                t = s;
                s = f;
                f = i;
            }

            else if(i > s){
                t = s;
                s = i;
            }

            else if(i > t)
                t = i;
        }
        return t == LLONG_MIN ? f : t;
    }
};