class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int res;
        int temp, tempD;
        int nL = nums.size();
        int i, j, k;
        for(int i = 0; i < nL-2; i++)
        {
            j = i+1;
            k = nL-1;
            while(j < k)
            {
                temp = nums[i] + nums[j] + nums[k];
                tempD = abs(temp - target);
                if(diff > tempD)
                {
                    diff = tempD;
                    res = temp;
                }
                //this is the tricky part
                //if the temp sum we got is bigger than target, then getting a smaller k
                //might get us a closer value to target
                //On the contrary, if the sum we got is smaller than target, then getting a bigger j
                //might get us a closer value to target
                if(temp > target)
                {
                    while(nums[k] == nums[k-1])
                    {
                        k--;
                    }
                    k--;
                }
                else if(temp < target)
                {
                    while(nums[j] == nums[j+1])
                    {
                        j++;
                    }
                    j++;
                }
                else
                {
                    return temp;
                }
            }
        }
        
        return res;
    }
};