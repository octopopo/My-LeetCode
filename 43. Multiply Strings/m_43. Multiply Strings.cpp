class Solution {
public:
    string multiply(string num1, string num2) {
        int oL = num1.size();
        int tL = num2.size();
        //handle some corner cases
        if(oL == 0 || tL == 0)
        {
            return "";
        }
        
        if(num1 == "0" || num2 == "0")
        {
            return "0";
        }
        
        if(num1 == "1")
        {
            return num2;
        }
        
        if(num2 == "1")
        {
            return num1;
        }
        
        vector<int> tempTime(110*110,0);
        
        /*
            123
           *456
        -------
        */
        
        int iPos, jPos;
        int tPos;
        char oC, tC;
        int oI, tI;
        int tTime;
        int carry;
        int addPtr = 0;
        for(int i = tL-1; i >= 0; i--)
        {
            iPos = tL-1-i;
            tC = num2[i];
            tI = tC - '0';
            for(int j = oL-1; j >= 0; j--)
            {
                jPos = oL-1-j;
                tPos = iPos + jPos;
                oC = num1[j];
                oI = oC - '0';
                //get the time of two digit
                tTime = oI * tI;
                tempTime[tPos] += tTime%10;
                addPtr = 1;
                if(tempTime[tPos] >= 10)
                {
                    tempTime[tPos] %= 10;
                    carry = 1;
                    while(carry)
                    {
                        tempTime[tPos+addPtr] += 1;
                        if(tempTime[tPos+addPtr] >= 10)
                        {
                            tempTime[tPos+addPtr] %= 10;
                            carry = 1;
                        }
                        else
                        {
                            carry = 0;
                        }
                        addPtr++;
                    }
                }
                carry = 0;
                if(tTime >= 10)
                {
                    addPtr = 1;
                    tPos += 1;
                    tTime /= 10;
                    tempTime[tPos] += tTime;
                    if(tempTime[tPos] >= 10)
                    {
                        tempTime[tPos] %= 10;
                        carry = 1;
                        while(carry)
                        {
                            tempTime[tPos+addPtr] += 1;
                            if(tempTime[tPos+addPtr] >= 10)
                            {
                                tempTime[tPos+addPtr] %= 10;
                                carry = 1;
                            }
                            else
                            {
                                carry = 0;
                            }
                            addPtr++;
                        }
                        
                    }
                }
                carry = 0;
            }
        }
        int lastPos;
        if(addPtr == 0)
        {
            lastPos = tPos + addPtr;
        }
        else
        {
            lastPos = tPos + addPtr-1;
        }
        string res;
        for(int i = 0; i <=lastPos; i++)
        {
            int tempN = tempTime[i];
            res.insert(res.begin(), (char)(tempN + '0'));
        }
        
        return res;
    }
};