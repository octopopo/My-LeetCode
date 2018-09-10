/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int iL = intervals.size();
        bool doneMerging = false;
        bool startMerging = false;
        if(iL == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        
        int nS = newInterval.start, nE = newInterval.end;
        int tempS, tempE;
        
        for(int i = 0; i < iL; i++)
        {
            if(!startMerging)
            {
                if(intervals[i].end < nS)
                {
                    res.push_back(intervals[i]);
                }
                else
                {
                    if(intervals[i].start > nE)
                    {
                        res.push_back(newInterval);
                        res.push_back(intervals[i]);
                        startMerging = true;
                        doneMerging = true;
                    }
                    else
                    {
                        startMerging = true;
                        tempS = min(intervals[i].start, newInterval.start);
                        tempE = max(intervals[i].end, newInterval.end);
                    }
                }
            }
            else
            {
                if(doneMerging)
                {
                    res.push_back(intervals[i]);
                }
                else
                {
                    if(intervals[i].start <= tempE)
                    {
                        tempE = max(tempE, intervals[i].end);
                    }
                    else
                    {
                        Interval mergedI(tempS, tempE);
                        res.push_back(mergedI);
                        res.push_back(intervals[i]);
                        doneMerging = true;
                    }
                }
            }
        }
        
        if(startMerging && !doneMerging)
        {
            Interval mergedI(tempS, tempE);
            res.push_back(mergedI);
        }
        
        if(!startMerging)
        {
            res.push_back(newInterval);
        }
        
        return res;
    }
};