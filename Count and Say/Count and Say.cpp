class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string lastRes;
        int count = 0;
        char target;
        char tempC;
        int sL = 0;
        for(int i = 1; i < n; i++)
        {
            lastRes = res;
            res.clear();
            sL = lastRes.size();
            target = lastRes[0];
            count = 1;
            for(int j = 1; j < sL; j++)
            {
                if(target != lastRes[j])
                {
                    tempC = '0' + count;
                    res.insert(res.end(),tempC);
                    res.insert(res.end(),target);
                    target = lastRes[j];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            tempC = '0' + count;
            res.insert(res.end(),tempC);
            res.insert(res.end(),target);
        }
        
        return res;
    }
};