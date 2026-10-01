class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> k;

        for(int i: nums1) k[i]++;

        for(int i: nums2){
            if(k[i]>0) res.push_back(i);
            k[i]--;
        }
        return res;
    }
};