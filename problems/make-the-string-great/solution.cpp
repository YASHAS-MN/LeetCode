class Solution {
public:
    string makeGood(string s) {
        string res;

        for(char c : s){
            if(!res.empty()){
                char l = res.back();
            
                if(l + 32 == c || l - 32 == c){
                    res.pop_back();
                    continue;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};