class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> c(501,0);

        for(int i : arr){
            c[i]++;
        }

        int res = -1;

        for(int i=1; i<501; i++){
            if( c[i] == i)
             res = i;
        }
        return res;
    }
};