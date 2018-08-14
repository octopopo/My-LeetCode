class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //building the set for both vector
        set<int> oSet(nums1.begin(), nums1.end());
        set<int> tSet(nums2.begin(), nums2.end());
        
        int oL = oSet.size(), tL = tSet.size();
        
        vector<int> v(oL + tL);
        
        //find the intersection between two set
        auto it = set_intersection(oSet.begin(), oSet.end(), tSet.begin(), tSet.end(), v.begin());
        
        v.resize(it-v.begin());
        
        return v;
    }
};