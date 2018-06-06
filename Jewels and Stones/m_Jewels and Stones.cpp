class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int m_map[52];
        int temp;
        int res = 0;
        for(int i = 0; i < 52; m_map[i++] = 0){}
               
            
        for(int i = 0 ; i < J.size(); i++){
            temp = J[i] <= 'Z' ? (J[i] - 'A') : (J[i] - 'a' + 26);
            m_map[temp] = 1;
        }
        
        
        for(int i = 0 ; i < S.size(); i++){
            temp = S[i] <= 'Z' ? (S[i] - 'A') : (S[i] - 'a' + 26);
            res += m_map[temp];
        }
        
        return res;
    }
};