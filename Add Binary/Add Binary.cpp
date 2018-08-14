class Solution {
public:
    string addBinary(string a, string b) {
        int aL = a.size()-1;
        int bL = b.size()-1;
    
        if(bL > aL)
        {
            string temp = a;
            a = b;
            b = temp;
            int tempL = aL;
            aL = bL;
            bL = tempL; 
        }
        
        bool carry = false;
        
        for(int i = aL, j = bL; i >=0 || j >= 0; i--, j--)
        {
            if(i >= 0 && j >= 0)
            {
                if(a[i] == '1' && b[j] == '1')
                {
                    a[i] = carry ? '1' : '0';
                    carry = true;
                }
                else if(a[i] == '0' && b[j] == '0')
                {
                    a[i] = carry ? '1' : '0';
                    carry = false;
                }
                else
                {
                    a[i] = carry ? '0' : '1';
                    carry = carry ? true : false;
                }
            }
            else if(i >= 0)
            {
                if(a[i] == '0')
                {
                    if(carry)
                    {
                        a[i] = '1';
                    }
                    carry = false;
                }
                else
                {
                    if(carry)
                    {
                        a[i] = '0';
                        carry = true;
                    }
                    else{
                        carry = false;
                    }
                }
            }
        }
        if(carry == true)
        {
            a.insert(a.begin(), '1');
        }
        
        return a;
        
    }
};