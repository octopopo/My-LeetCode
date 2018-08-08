class Solution {
public:
    vector<string> res;
    unordered_map<char, vector<char>> m_map;
    vector<string> letterCombinations(string digits) {
        vector<char> tempVector;
        int tempPos = 0;
        vector<string> res;
        vector<string> res2;
        int dL = digits.size();
        if(dL == 0)
        {
            return res;
        }
        
        //build the hashmap
        for(int i = 2; i <= 9; i++)
        {
            if(i >= 2 && i <= 7)
            {
                tempPos = 3 * (i-2);
                tempVector.push_back('a' + tempPos);
                tempVector.push_back('a' + tempPos + 1);
                tempVector.push_back('a' + tempPos + 2);
                if(i == 7)
                {
                    tempVector.push_back('a' + tempPos + 3);
                }
            }
            else if(i == 8)
            {
                tempVector.push_back('t');
                tempVector.push_back('u');
                tempVector.push_back('v');
            }
            else if(i == 9)
            {
                tempVector.push_back('w');
                tempVector.push_back('x');
                tempVector.push_back('y');
                tempVector.push_back('z');
            }
            
            m_map['0' + i] = tempVector;
            tempVector.clear();
        }
        
        return consString(digits);
    }
    
    vector<string> consString(string digits)
    {
        string tempS = "";
        int dL = digits.size();
        vector<string> tempV;
        if(digits.size() == 1)
        {
            for(int i = 0; i < m_map[digits[0]].size(); i++)
            {
                tempS += m_map[digits[0]][i];
                cout << tempS << endl;
                tempV.push_back(tempS);
                tempS = "";
            }
            return tempV;
        }
        
        vector<string> subV;
        subV = consString(digits.substr(1, dL-1));
        
        for(int i = 0; i < m_map[digits[0]].size(); i++)
        {
            for(int j = 0; j < subV.size(); j++)
            {
                tempS += m_map[digits[0]][i];
                tempV.push_back(tempS + subV[j]);
                tempS = "";
            }
        }
        
        return tempV;
    }
};