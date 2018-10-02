class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> resSet;
        int nL = nums.size();
        if(nL == 0)
        {
            return res;
        }
        else
        {
            for(int i = 0; i < nL; i++)
            {
                vector<int> tempRes;
                vector<int> tempNum(nums.begin(), nums.end());
                GetPermute(tempRes, i, resSet, tempNum, nL);
            }
        }
        vector<vector<int>> resI(resSet.begin(), resSet.end());
        return resI;
    }
    
    void GetPermute(vector<int> tempRes, int target, set<vector<int>>& resSet, vector<int> tempNum, int nL)
    {
        if(target < nL)
        {
            tempRes.push_back(tempNum[target]);
            if(target != nL-1)
            {
                tempNum[target] = tempNum[nL-1];
            }
            nL--;
            if(nL == 0)
            {
                cout <<"push"<<endl;
                resSet.insert(tempRes);
                return;
            }
            else
            {
                for(int i = 0; i < nL; i++)
                {
                    GetPermute(tempRes, i, resSet, tempNum, nL);
                }
            }
        }
        return;
    }
};