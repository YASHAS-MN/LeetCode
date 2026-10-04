class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> g;
        for(char c: s) g[c]++;
        vector<pair<char,int>> p;
        for(auto& i: g) p.push_back({i.first, i.second});
        sort(p.begin(), p.end(), [](auto& a, auto& b){return a.second>b.second;});
        string ans;
        for(auto& i: p)
            for(int j=0; j<i.second; j++)
                ans.push_back(i.first);
        return ans;
    }
};