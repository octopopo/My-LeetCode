class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return -1;
        }
        int start = 0, end = nums.size()-1;
        
        int mid = (start + end) / 2;
        int tempM, tempS, tempE;
        tempM = nums[mid];
        tempS = nums[start];
        tempE = nums[end];
        if(target == tempM)
        {
            return mid;
        }
        else if(target == tempE)
        {
            return end;
        }
        else if(target == tempS)
        {
            return start;
        }
        while(mid != start && mid != end)
        {
            if(target > tempE && target < tempS)
            {
                return -1;
            }
            if(tempE > tempM && tempM > tempS)
            {
                if(target > tempM)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if(tempM > tempS && tempS > tempE)
            {
                if(target > tempM)
                {
                    start = mid + 1;
                }
                else
                {
                    if(target > tempS)
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
            }
            else if(tempS > tempE && tempE > tempM)
            {
                if(target < tempM)
                {
                    end = mid - 1;
                }
                else
                {
                    if(target > tempS)
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
            }
            mid = (start + end) / 2;
            
            tempM = nums[mid];
            tempS = nums[start];
            tempE = nums[end];
            if(target == tempM)
            {
                return mid;
            }
            else if(target == tempE)
            {
                return end;
            }
            else if(target == tempS)
            {
                return start;
            }
        }
        
        return -1;
    }
};