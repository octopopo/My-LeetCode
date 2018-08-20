class Solution {
public:
    vector<int> *nP;
    vector<vector<int>> permute(vector<int>& nums) {
        int nL = nums.size();
        vector<int> temp;
        vector<vector<int>> temp1;
        vector<vector<int>> res;
        vector<bool> nState(nL, true);
        if(nL == 0)
        {
            return res;
        }
        else if(nL == 1)
        {
            temp.push_back(nums[0]);
            res.push_back(temp);
            return res;
        }
        else
        {
            for(int i = 0; i < nL; i++)
            {
                if(nState[i])
                {
                    nState[i] = false;
                    temp1 = getPermute(nums, nL-1, nState, nums[i]);
                    for(int j = 0; j < temp1.size(); j++)
                    {
                        res.push_back(temp1[j]);
                    }
                    nState[i] = true;
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> getPermute(vector<int>& nums, int remain, vector<bool> nState, int target)
    {
        int nL = nums.size();
        vector<vector<int>> res;
        vector<vector<int>> temp1;
        vector<int> temp;
        if(remain == 0)
        {
            temp.push_back(target);
            res.push_back(temp);
            return res;
        }
        else
        {
            remain -= 1;
            for(int i = 0; i < nL; i++)
            {
                if(nState[i] == true)
                {
                    nState[i] = false;
                    temp1 = getPermute(nums, remain, nState, nums[i]);
                    for(int j = 0; j < temp1.size(); j++)
                    {
                        temp = temp1[j];
                        temp.push_back(target);
                        res.push_back(temp);
                    }
                    nState[i] = true;
                }
            }
            
            return res;
        }
    }
};