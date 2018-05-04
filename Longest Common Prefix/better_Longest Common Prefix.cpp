class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        string res = "";
        int strNum = strs.size();
        
        for(int i = 0; i >= 0; i++){
            for(int j = 0; j < strNum; j++){
                if(i >= strs[j].size())
                    return res;
                if(j > 0 && strs[j][i] != strs[j-1][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};