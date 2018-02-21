class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int tempSum = 0;
        int aCount = a.size()-1;
        int bCount = b.size()-1;
        string res;
        
        while(aCount >=0 || bCount >=0){
            if(aCount >= 0 && bCount >=0){
                if(a[aCount] == '1' && b[bCount] == '1'){
                    //int toIn = carry == 1 ? 1 : 0;
                    res.insert(0,to_string(carry));
                    carry = 1;
                }
                else if(a[aCount] == '0' && b[bCount] == '0'){
                    res.insert(0,to_string(carry));
                    carry = 0;
                }
                else{
                    if(carry == 1){
                        res.insert(0,to_string(0));
                        carry = 1;
                    }
                    else{
                        res.insert(0,to_string(1));
                        carry = 0;
                    }
                }
            }
            else if(aCount >= 0){
                if(a[aCount] == '0'){
                    res.insert(0,to_string(carry));
                    carry = 0;
                }
                else{
                    if(carry == 1){
                        res.insert(0,to_string(0));
                        carry = 1;
                    }
                    else{
                        res.insert(0,to_string(1));
                        carry = 0;
                    }
                }
            }
            else if(bCount >= 0){
                if(b[bCount] == '0'){
                    res.insert(0,to_string(carry));
                    carry = 0;
                }
                else{
                    if(carry == 1){
                        res.insert(0,to_string(0));
                        carry = 1;
                    }
                    else{
                        res.insert(0,to_string(1));
                        carry = 0;
                    }
                }
            }
            aCount--;
            bCount--;
        }
        
        if(carry == 1)
            res.insert(0,to_string(1));
        
        return res;
    }
};