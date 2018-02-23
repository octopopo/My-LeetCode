class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        string tok;
        //vector<string> m_map(26);
        unordered_map<char, string> m_map;
        unordered_map<string, char> m_map2;
        int i = 0;
        while(getline(iss, tok, ' ')){
            char pat = pattern[i];
            if(m_map.find(pat) == m_map.end())
                m_map[pat] = tok;
            else{
                if(tok != m_map[pat])
                    return false;
            }
            
            if(m_map2.find(tok) == m_map2.end())
                m_map2[tok] = pat;
            else{
                if(pat != m_map2[tok])
                    return false;
            }
            i++;
        }
        cout << i << endl;
        if(i!=(int)pattern.size())
            return false;
        
        return true;
    }
};