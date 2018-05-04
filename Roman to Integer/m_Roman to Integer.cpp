class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m_map;
        m_map['M'] = 1000;
        m_map['D'] = 500;
        m_map['C'] = 100;
        m_map['L'] = 50;
        m_map['X'] = 10;
        m_map['V'] = 5;
        m_map['I'] = 1;
        int sum = 0;
        int sSize = s.size();
        int temp = 0;
        for(int i = 0; i < sSize; i++){
            if(s[i] == 'I'){
                temp += m_map[s[i]];
                if(s[i+1] == 'X' || s[i+1] == 'V'){
                    sum -= temp;
                    sum += m_map[s[++i]];
                    temp = 0;
                }
                else if(s[i+1] == 'I'){
                    continue;
                }
                else{
                    sum += temp;
                    temp = 0;
                }
            }
            else if(s[i] == 'X'){
                temp += m_map[s[i]];
                if(s[i+1] == 'C' || s[i+1] == 'L'){
                    sum -= temp;
                    sum += m_map[s[++i]];
                    temp = 0;
                }
                else if(s[i+1] == 'X'){
                    continue;
                }
                else{
                    sum += temp;
                    temp = 0;
                }
                
            }   
            else if(s[i] == 'C'){
                temp += m_map[s[i]];
                if(s[i+1] == 'D' || s[i+1] == 'M'){
                    sum -= temp;
                    sum += m_map[s[++i]];
                    temp = 0;
                }
                else if(s[i+1] == 'C'){
                    continue;
                }
                else{
                    sum += temp;
                    temp = 0;
                }
            }
            else{
                sum += m_map[s[i]];
            }
        }
        //sum += temp;
        return sum;
    }
};