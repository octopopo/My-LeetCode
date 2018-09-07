class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> m_map;
        vector<int> res(2,0);
        int temp;
        for(int i = 0; i < nums.size(); i++)
        {
            temp = target - nums[i];
            if(m_map.count(temp))
            {
                res[0] = m_map[temp];
                res[1] = i;
                break;
            }
            m_map[nums[i]] = i;
        }
        
        return res;
    }
};