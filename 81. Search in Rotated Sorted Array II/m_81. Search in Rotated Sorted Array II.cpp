class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int nL = nums.size();
        if(nL == 0)
        {
            return false;
        }
        
        bool isRotated = false;
        int peak = 0;
        int valley = 0;
        
        for(int i = 0; i < nL-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                valley = i+1;
                peak = i;
                break;
            }
        }
        
        if(valley != 0 || peak != 0)
        {
            isRotated = true;
        }
        
        //find which session the number might be is 
        int head = 0;
        int tail = nL-1;
        if(isRotated)
        {
            if(target == nums[peak] || target == nums[valley])
            {
                return true;
            }
            else if(target > nums[peak] || target < nums[valley])
            {
                return false;
            }
            else if(target <= nums[peak] && target >= nums[head])
            {
                tail = peak;
            }
            else if(target >= nums[valley] && target <= nums[tail])
            {
                head = valley;
            }
        }
        
        //now I got the session that it might be in, do binary search
        //cout << head << " " << tail << endl;
        int mid = (head + tail) / 2;
        
        while(head <= tail)
        {
            //cout << head << " " << tail << endl;
            if(target == nums[mid])
            {
                return true;
            }
            else if(target < nums[mid])
            {
                tail = mid-1;
            }
            else if(target > nums[mid])
            {
                head = mid+1;
            }
            mid = (head + tail) / 2;
        }
        
        return false;
    }
};