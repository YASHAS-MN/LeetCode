class Solution {
public:
int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);}
    bool hasGroupsSizeX(vector<int>& deck) {
        

        unordered_map<int, int> count;
        for (int c : deck) {
            count[c]++;
        }
        
        int res = 0;
        for (auto& pair : count) {
            res = gcd(res, pair.second);
        }
        
        return res >= 2;
    }
};