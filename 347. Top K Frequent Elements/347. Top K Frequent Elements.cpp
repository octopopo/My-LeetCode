class Solution {
public:
    
    static bool compM(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int nL = nums.size();
        vector<int> res(k, 0);
        vector<int> countRec(k, 0);
        if(nL == 0)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        int target = nums[0];
        int count = 1;
        
        for(int i = 1; i < nL; i++)
        {
            if(nums[i] == target)
            {
                count++;
            }
            else
            {
                cout << target << " " << count << ":" << countRec[0] << endl;
                if(count > countRec[0])
                {
                    countRec[0] = count;
                    res[0] = target;
                }
                for(int j = 1; j < k; j++)
                {
                    if(count > countRec[j])
                    {
                        countRec[j-1] = countRec[j];
                        res[j-1] = res[j];
                        countRec[j] = count;
                        res[j] = target;
                    }
                    else
                    {
                        break;
                    }
                }
                
                count = 1;
                target = nums[i];
            }
        }
        if(count > countRec[0])
        {
            countRec[0] = count;
            res[0] = target;
        }
        for(int j = 1; j < k; j++)
        {
            if(count > countRec[j])
            {
                countRec[j-1] = countRec[j];
                res[j-1] = res[j];
                countRec[j] = count;
                res[j] = target;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};