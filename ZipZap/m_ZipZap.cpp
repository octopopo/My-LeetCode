class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string res = "";
        string *temp = new string[numRows];
        
        int sSize = s.size();
        int tQ = 0;
        int qQ = numRows*2-2;
        
        int tT = 0;
        for(int i = 0; i < sSize; i++){
            tQ = i % qQ;
            if(tQ == 0){
                temp[0]+= s[i];
            }
            else if(tQ == numRows-1){
                temp[numRows-1] += s[i];
            }
            else if(tQ > 0 && tQ < numRows-1){
                temp[tQ] += s[i];
            }
            else if(tQ > numRows-1){
                tT = tQ - numRows+1;
                temp[numRows-tT-1] += s[i];
            }
        }
        
        for(int i = 0; i < numRows; i++){
            res += temp[i];
        }
        
        return res;
    }
};