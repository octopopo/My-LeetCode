class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> head, tail, *phead, *ptail;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if(!wordSet.count(endWord))
        {
            return 0;
        }
        
        head.insert(beginWord);
        tail.insert(endWord);
        wordSet.erase(endWord);
        
        int hS = head.size();
        int tS = tail.size();
        
        string tempS;
        
        int dist = 2;
        
        while(!head.empty() && !tail.empty())
        {
            //letting phead always pointing to the shorter one, so that the later iteration can interate faster
            if(hS <= tS)
            {
                phead = &head;
                ptail = &tail;
            }
            else
            {
                phead = &tail;
                ptail = &head;
            }
            
            unordered_set<string> tempSet;
            
            for(auto i = phead->begin(); i != phead->end(); i++)
            {
                tempS = *i;
                wordSet.erase(tempS);
                for(int j = 0; j < tempS.size(); j++)
                {
                    char letter = tempS[j];
                    for(int k = 0; k < 26; k++)
                    {
                        tempS[j] = k + 'a';
                        if(ptail->count(tempS))
                        {
                            return dist;
                        }
                        if(wordSet.count(tempS))
                        {
                            tempSet.insert(tempS);
                            wordSet.erase(tempS);
                        }
                    }
                    tempS[j] = letter;
                }
            }
            
            dist++;
            swap(*phead, tempSet);  
        }
        
        return 0;
    }
};