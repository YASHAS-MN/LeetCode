class Solution {
public:
    bool uniformArray(vector<int>& n) {
        int mn = *min_element(n.begin(), n.end());

        if(mn%2 == 1)
            return true;

        for(int x : n){
            if(x%2==1)
                return false;
        }         
    return true;
    }
};