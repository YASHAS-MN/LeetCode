class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 9999999;
        int pro = 0;

        for(int p : prices)
        {
            if(p < min)
            {
                min = p;
            }
            else if(p-min > pro)
            {
                pro = p -min;
            }
        }
        return pro;
    }
};