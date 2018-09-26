class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int head = 0;
        int nL = nums.size();
        if(nL == 0)
        {
            vector<int> newR{-1,-1};
            return newR;
        }
        int tail = nL-1;
        if(nums[head] == target && nums[tail] == target)
        {
            vector<int> newR{head,tail};
            return newR;
        }
        
        int pPos = biSearch(nums, head, tail, target);
        if(pPos == -1)
        {
            vector<int> newR{-1,-1};
            return newR;
        }
        
        int tempHead = pPos, tempTail = pPos;
        
        if(tempHead > 0)
        {
            while(true)
            {
                pPos = biSearch(nums, 0, tempHead-1, target);
                if(pPos == -1)
                {
                    break;
                }
                else
                {
                    if(pPos < tempHead)
                    {
                        tempHead = pPos;
                    }
                }
            }
        }
        
        if(tempTail < nL-1)
        {
            while(true)
            {
                pPos = biSearch(nums, tempTail+1, nL-1, target);
                if(pPos == -1)
                {
                    break;
                }
                else
                {
                    if(pPos > tempTail)
                    {
                        tempTail = pPos;
                    }
                }
            }
        }
        
        vector<int> res{tempHead, tempTail};
        
        return res;
        
    }
    
    int biSearch(vector<int> &nums, int stP, int enP, int target)
    {
        while(stP <= enP)
        {
            int midP = (stP + enP) / 2;
            if(nums[stP] == target)
            {
                return stP;
            }
            else if(nums[midP] == target)
            {
                return midP;
            }
            else if(nums[enP] == target)
            {
                return enP;
            }
            if(nums[midP] > target)
            {
                enP = midP-1;
            }
            else if(nums[midP] < target)
            {
                stP = midP+1;
            }
            else
            {
                return midP;
            }
        }
        return -1;
    }
};