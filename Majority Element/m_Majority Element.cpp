class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> m_map;
        int nSize = nums.size();
        int n2 = nSize/2;
        for(int i = 0; i < nSize; i++)
        {
            if(++m_map[nums[i]] > n2)
            {
                return nums[i];
            }
        }
        
        return 0;
    }
};