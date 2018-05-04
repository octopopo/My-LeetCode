class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m_map;
        vector<int> res;
        //res = new vector<int>[2];
        
        int nSize = nums.size();
        int rem;
        
        for(int i = 0; i < nSize; i++){
            rem = target - nums[i];
            unordered_map<int,int>::iterator it = m_map.find(rem);
            if(it != m_map.end()){
                if(i != m_map[rem]){
                    res.push_back(m_map[rem]);
                    res.push_back(i);
                    break;
                }
            }
            m_map[nums[i]] = i;
        }
        
        return res;
    }
};