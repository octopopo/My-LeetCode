class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int nL = nums.size();
        if(nL == 0)
        {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        //push all the single element
        for(int i = 0; i < nL; i++)
        {
            vector<int> tempRes{nums[i]};
            res.push_back(tempRes);
            /*while(nums[i+1] == nums[i] && i < nL)
            {
                i++;
            }*/
        }
        
        getAllSet(res, nums, nL);
        vector<int> emptySet;
        res.push_back(emptySet);
        return res;
    }
    
    void getAllSet(vector<vector<int>> &res, vector<int>& nums, int nL)
    {
        for(int length = 2; length <= nL; length++)
        {
            //vector<int> tempRes(length);
            vector<int> tempRes;
            dfs(tempRes, res, length, 0, nums, nL, 0);
        }
        return;
    }
    
    void dfs(vector<int> tempRes, vector<vector<int>> &res, int length, int pos, vector<int> &nums, int nL, int nowPos)
    {
        if(pos == length)
        {
            res.push_back(tempRes);
        }
        for(int i = nowPos; i < nL; i++)
        {
            if(i > nL - (length - pos))
            {
                break;
            }
            //cout << pos << endl;
            //tempRes[pos] = nums[i];
            tempRes.push_back(nums[i]);
            dfs(tempRes, res, length, pos+1, nums, nL, i+1);
            tempRes.pop_back();
            /*while(nums[i+1] == nums[i] && i < nL)
            {
                i++;
            }*/
        }
        return;
    }
};