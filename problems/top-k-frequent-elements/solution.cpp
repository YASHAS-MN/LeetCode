class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> g;

        for(int i: nums) g[i]++;

        vector<pair<int, int>> p;

        for(auto& i: g) p.push_back({i.first, i.second});

        sort(p.begin(), p.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        vector<int> res;

        for(int i=0; i<k; i++) res.push_back(p[i].first);

        return res;
    }
};