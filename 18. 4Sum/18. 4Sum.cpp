class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int tL = nums.size();
        vector<vector<int>> res;
        int head = 0;
        int tail = tL-1;
        int secTail, secHead;
        int firN, secN, thiN, forN;
        int newTarget;
        while(tail > 2)
        {
            forN = nums[tail];
            newTarget = target - forN;
            for(head = 0; head < tail-2; head++)
            {
                firN = nums[head];
                secTail = tail-1;
                secHead = head+1;
                newTarget = newTarget - firN;
                while(secHead < secTail)
                {
                    secN = nums[secHead];
                    thiN = nums[secTail];
                    if(secN + thiN > newTarget)
                    {
                        secTail--;
                        while(nums[secTail] == nums[secTail+1])
                        {
                            secTail--;
                        }
                    }
                    else if(secN + thiN < newTarget)
                    {
                        secHead++;
                        while(nums[secHead] == nums[secHead-1])
                        {
                            secHead++;
                        }
                    }
                    else
                    {
                        vector<int> tempRes{firN, secN, thiN, forN};
                        res.push_back(tempRes);
                        secHead++;
                        secTail--;
                        while(nums[secTail] == nums[secTail+1])
                        {
                            secTail--;
                        }
                        while(nums[secHead] == nums[secHead-1])
                        {
                            secHead++;
                        }
                    }
                    
                    
                }
                
                newTarget = target - forN;
                while(nums[head] == nums[head+1])
                {
                    head++;
                }
            }
            
            tail--;
            while(nums[tail] == nums[tail+1])
            {
                tail--;
            }
        }
        
        return res;
    }
};