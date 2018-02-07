class Solution {
public:
    int countSegments(string s) {
        const char *sc = s.c_str();
        char *pc;
        pc = strtok((char*)sc," ");
        int res = 0;
        while(pc != NULL){
            res++;
            pc = strtok(NULL," ");
        }
        return res;
    }
};