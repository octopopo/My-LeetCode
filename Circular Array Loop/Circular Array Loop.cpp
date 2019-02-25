class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int nLength = nums.size();
        if(nLength == 1)
        {
            return false;
        }
        //true mean forward, false mean backward
        bool direction = true;
        unordered_set<int> vectorBeenTo;
        int count = 0;
        int start = 0;
        //cout << "start is: " <<  start << endl;
        for(int i = 0; i < nLength; i++)
        {
            //cout << "i: " << i << endl;
            vectorBeenTo.insert(i);
            start = i;
            direction = nums[i] > 0 ? true : false;
            int step = i + nums[i];
            if(step < 0)
            {
                step = step%nLength;
                step = nLength + step;
            }
            else if(step >= nLength)
            {
                step = step%nLength;
            }
            count = 1;
            while(1)
            {
                //cout << "step is: " <<  step << endl;
                if(vectorBeenTo.count(step))
                {
                    if(count <= 1)
                    {
                        break;
                    }
                    else
                    {
                        if(step == start)
                        {
                            return true;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                if(direction)
                {
                    if(nums[step] < 0)
                    {
                        break;
                    }
                }
                else
                {
                    if(nums[step] > 0)
                    {
                        break;
                    }
                }


                if(vectorBeenTo.size() == nLength)
                {
                    //cout << "full" << endl;
                    return false;
                }
                vectorBeenTo.insert(step);

                step = step + nums[step];
                count++;
                if(step < 0)
                {
                    step = step%nLength;
                    step = nLength + step;
                }
                else if(step >= nLength)
                {
                    step = step%nLength;
                }
            }
            vectorBeenTo.clear();
        }
        cout << "here" << endl;
        return false;
    }
};