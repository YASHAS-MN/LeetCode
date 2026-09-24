class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 999;
        int b = 999;

        for(int i : prices){
            if(i < a ){
                b = a;
                a = i;
            }else if(i < b)
                b = i;
        }

        int c = a + b;
        if(c <= money)
            return money-c;
        return money;
    }
};