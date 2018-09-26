class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int cL = candidates.size();
        vector<vector<int>> res;
        set<vector<int>> resSet;
        map<int, set<vector<int>>> iToV;
        if(cL == 0)
        {
            return res;
        }
        
        int tempTarget, tempSum;
        int tempC;
        for(int i = 0; i < cL; i++)
        {
            tempC = candidates[i];
            if(tempC > target)
            {
                break;
            }
            vector<int> tempV {tempC};
            for(int i = tempC; i <= target; i+=tempC)
            {
                //cout << "i: " << i << endl;
                for(auto a = iToV.begin(); a != iToV.end(); a++)
                {
                    //cout << i << " " << a->first << endl;
                    int tempSum = i + a->first;
                    if(tempSum > target)
                    {
                        break;
                    }
                    //cout << i << " " << a->first << " " << tempSum << endl;
                    set<vector<int>> tempSet = a->second;
                    for(auto b = tempSet.begin(); b != tempSet.end(); b++)
                    {
                        vector<int> tempSV = *b;
                        tempSV.insert(tempSV.end(), tempV.begin(), tempV.end());
                        if(tempSum == target)
                        {
                            resSet.insert(tempSV);
                        }
                        else
                        {
                            iToV[tempSum].insert(tempSV);
                        }
                    }
                }
                if(i == target)
                {
                    resSet.insert(tempV);
                }
                iToV[i].insert(tempV);
                tempV.push_back(tempC);
            }
        }
        
        res.insert(res.end(), resSet.begin(), resSet.end());
        
        return res;
    }
};