class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> wordToVisit;
        int dist = 2;
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        
        findNextWord(beginWord, wordToVisit, wordList);
        
        int qSize;
        string temp;
        while(!wordToVisit.empty())
        {
            qSize = wordToVisit.size();
            for(int i = 0; i < qSize; i++)
            {
                temp = wordToVisit.front();
                wordToVisit.pop();
                if(endWord == temp)
                {
                    return dist;
                }
                findNextWord(temp, wordToVisit, wordList);
            }
            dist++;
        }
        
        return 0;
        
    }
    
    void findNextWord(string targetWord, queue<string>& wordToVisit, vector<string>& wordList)
    {
        int diff;
        int wL = wordList.size();
        vector<int> haveToErase;
        
        for(int i = 0; i < wL; i++)
        {
            if(wordList[i] != "")
            {
                diff = checkDiff(targetWord, wordList[i]);
                if(diff == 1)
                {
                    wordToVisit.push(wordList[i]);
                    wordList[i] = "";
                }
            }
        }
        
        return;
    }
    
    int checkDiff(string target, string compW)
    {
        int tL = target.size();
        int diff = 0;
        for(int i = 0; i < tL; i++)
        {
            if(target[i] != compW[i])
            {
                diff++;
            }
        }
        
        return diff;
    }
};