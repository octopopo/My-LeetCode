class Solution {
public:
    int compress(vector<char>& chars) {
        int pnt = 0;
        int cnt = 0;
        int n = chars.size();
        char tar;
        for(int i = 0; i < n; i++){
            if(i == 0){
                tar = chars[i];
                cnt = 0;
            }
            if(chars[i] != tar){
                chars[pnt] = tar;
                tar = chars[i];
                pnt++;
                cout << cnt << endl;
                if(cnt == 1){
                    
                }
                else{
                    if(cnt >= 100){
                        chars[pnt] = (cnt/100) + '0';
                        pnt++;
                        cnt = cnt % 100;
                    }
                    if(cnt >= 10 && cnt < 100){
                        chars[pnt] = (cnt/10) + '0';
                        pnt++;
                        cnt = cnt % 10;
                    }
                    if(cnt < 10 && cnt >= 0){
                        chars[pnt] = cnt + '0';
                        pnt++;
                    }
                }
                cnt = 1;
            }
            else{
                cnt++;
            }
            if(i == n-1){
                chars[pnt] = tar;
                pnt++;
                if(cnt == 1){
                    
                }
                else{
                    if(cnt >= 100){
                        chars[pnt] = (cnt/100) + '0';
                        pnt++;
                        cnt = cnt % 100;
                    }
                    if(cnt >= 10 && cnt < 100){
                        chars[pnt] = (cnt/10) + '0';
                        pnt++;
                        cnt = cnt % 10;
                    }
                    if(cnt < 10 && cnt >= 0){
                        chars[pnt] = cnt + '0';
                        pnt++;
                    }
                }
            }
        }
        return pnt;
    }
};