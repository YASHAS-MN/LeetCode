class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child=0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(int cookie : s){
            if(child<g.size() && cookie >= g[child])
                child++;
        }
    return child;    
    }
};