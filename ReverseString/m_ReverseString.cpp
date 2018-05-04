class Solution {
public:
    string reverseString(string s) {
        int sSize = s.size();
        char temp;
        int back;
        for(int i = 0; i < sSize/2; i++){
            back = sSize - 1 -i;
            temp = s[i];
            s[i] = s[back];
            s[back] = temp;
        }
        
        return s;
    }
};