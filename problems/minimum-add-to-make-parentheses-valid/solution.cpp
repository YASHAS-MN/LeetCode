class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0, c=0;

        for(char i: s){
            if(i=='(')
                o++;
            else if(o>0)   
                o--;
            else
                c++;
        }
        return o+c;
    }
};