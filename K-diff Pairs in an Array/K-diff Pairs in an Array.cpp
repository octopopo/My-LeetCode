class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mMap;
        int nLength = nums.size();
        int target;
        int count = 0;
        if(nLength == 0 || k < 0)
        {
            return 0;
        }
        
        for(int i = 0; i < nLength; i++)
        {
            mMap[nums[i]]++;
        }
        
        if(k == 0)
        {
            for(auto i = mMap.begin(); i != mMap.end(); i++)
            {
                if(i->second >= 2)
                {
                    count++;
                }
            }
        }
        else
        {
            for(auto i = mMap.begin(); i != mMap.end(); i++)
            {
                target = i->first + k;
                if(mMap.count(target))
                {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};