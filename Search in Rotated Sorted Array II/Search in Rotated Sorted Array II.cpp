class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int nL = nums.size();
        if(nL == 0)
        {
            return false;
        }
        else if(nL == 1)
        {
            return nums[0] == target;
        }
        int head = 0, tail = nL-1, mid;
        int peak = 0, valley = 0;
        bool isRotated = false;
        //Search for peak and valley
        for(int i = 0; i < nL-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                peak = i;
                valley = i+1;
            }
        }
        
        if(valley != 0 || peak != 0)
        {
            isRotated = true;
        }
        
        if(isRotated)
        {
            if(target <= nums[peak] && target > nums[head])
            {
                tail = peak;
            }
            else if(target >= nums[valley] && target < nums[tail])
            {
                head = valley;
            }
            else if(target > nums[peak])
            {
                return false;
            }
            else if(target < nums[valley])
            {
                return false;
            }
        }
        
        mid = (head + tail) /2;
        //cout << head << " " << mid << " " << tail << endl;
        while(head < tail)
        {
            if(nums[mid] == target || nums[head] == target || nums[tail] == target)
            {
                return true;
            }
            if(nums[mid] > target)
            {
                tail = mid -1;
            }
            else
            {
                head = mid + 1;
            }
            
            mid = (head + tail) / 2;
        }
        
        return false;
    }
};