class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        unordered_map<int, string> m_map;
        int temp, temp5;
        m_map[1] = "I";
        m_map[5] = "V";
        m_map[10] = "X";
        m_map[50] = "L";
        m_map[100] = "C";
        m_map[500] = "D";
        m_map[1000] = "M";
        for(int i = 0; i < 4; i++){
            if(num == 0)
                return res;
            else{
                temp = num%10;
                num /= 10;
                if(temp < 5){
                    if(temp == 4){
                        temp = 1 * pow(10, i);
                        temp5 = 5 * pow(10, i);
                        res = m_map[temp] + m_map[temp5] + res;
                       // res = m_map[]
                    }
                    else{
                        temp5 = 1 * pow(10, i);
                        for(int a = 0; a < temp; a++)
                            res = m_map[temp5] + res;
                    }
                }
                else if(temp == 5){
                    temp = 5 * pow(10, i);
                    res = m_map[temp] + res;
                }
                else{
                    if(temp == 9){
                        temp = 1 * pow(10, i);
                        temp5 = 10 * pow(10, i);
                        res = m_map[temp] + m_map[temp5] + res;
                    }
                    else{
                        temp5 = 1 * pow(10, i);
                        for(int a = 0; a < temp-5; a++)
                            res = m_map[temp5] + res;
                        temp5 = 5 * pow(10, i);
                        res = m_map[temp5] + res;
                    }
                }
            }
        }
        
        return res;
    }
};