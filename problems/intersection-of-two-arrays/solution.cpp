class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hs;
        vector<int> res;

        for(int a : nums1)
            hs.insert(a);

        for(int b : nums2){
            if(hs.count(b))
                res.push_back(b);
            hs.erase(b);
        }
        return res;
    }
};