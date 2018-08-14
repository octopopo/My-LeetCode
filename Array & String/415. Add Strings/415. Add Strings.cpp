class Solution {
public:
    string addStrings(string num1, string num2) {
        int oL = num1.size(), tL = num2.size();
        string swapS;
        int swapL;
        int tempO, tempT;
        int temp;
        int carry = 0;
        if(oL < tL)
        {
            swapL = oL;
            oL = tL;
            tL = swapL;
            
            swapS = num1;
            num1 = num2;
            num2 = swapS;
        }
        
        int i, j;
        
        for(i = oL-1, j = tL-1; i >= 0 && j >= 0; i--, j--)
        {
            tempO = getInt(num1[i]);
            tempT = getInt(num2[j]);
            temp = tempO + tempT + carry;
            carry = temp/10;
            temp %= 10;
            num1[i] = getChar(temp);
        }
        while(carry && i >= 0)
        {
            tempO = getInt(num1[i]);
            temp = tempO + carry;
            carry = temp/10;
            temp%=10;
            num1[i] = getChar(temp);
            i--;
        }
        if(carry)
        {
            num1.insert(num1.begin(), '1');
        }
        
        return num1;
    }
    
    
    int getInt(char c)
    {
        return c - '0';
    }
    
    char getChar(int i)
    {
        return i + '0';
    }
};