class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dSize = digits.size()-1;
        if(digits[dSize] + 1 < 10){
            digits[dSize]++;
            return digits;
        }
        else
        {
            for(int j = dSize; j >= 0; j--)
            {
                if(++digits[j] < 10)
                {
                    return digits;
                }
                else
                {
                    digits[j] = 0;
                    if(j == 0)
                    {
                        digits.insert(digits.begin(),1);
                        return digits;
                    }
                }
            }
        }
        return digits;
    }
};