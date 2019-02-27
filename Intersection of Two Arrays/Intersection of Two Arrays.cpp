class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int fLength = nums1.size();
        int sLength = nums2.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unordered_set<int> seen;
        for(int i = 0; i < fLength; i++)
        {
            seen.insert(nums1[i]);
        }
        
        for(int j = 0; j < sLength; j++)
        {
            if(seen.count(nums2[j]))
            {
                res.push_back(nums2[j]);
            }
            while(j+1 < sLength && nums2[j+1] == nums2[j])
            {
                j++;
            }
        }
        
        return res;
    }
};