class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> g;

        for(string i: strs){
            string k = i;
            sort(k.begin(), k.end());
            g[k].push_back(i);
        }   

        for(auto& i: g) { res.push_back(i.second); }

        return res;
    }
};