class Solution {
public:
    string nextClosestTime(string time) {
        int sL = time.size();
        int record[4];
        int tempP = 0;
        
        record[0] = time[0] - '0';
        record[1] = time[1] - '0';
        record[2] = time[3] - '0';
        record[3] = time[4] - '0';
        
        int hour = record[0] * 10 + record[1];
        int minute = record[2] * 10 + record[3];
        
        int minuteTop = 60;
        int temp;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                temp = record[i] * 10 + record[j];
                if(temp > minute && temp < minuteTop)
                {
                    minuteTop = temp;
                }
            }
        }
        
        if(minuteTop != 60)
        {
            return getValidString(hour, minuteTop);
        }
        
        int hourTop = 24;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                temp = record[i] * 10 + record[j];
                if(temp > hour && temp < hourTop)
                {
                    hourTop = temp;
                }
            }
        }
        
        if(hourTop != 24)
        {
            minuteTop = 60;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    temp = record[i] * 10 + record[j];
                    if(temp >= 0 && temp < minuteTop)
                    {
                        minuteTop = temp;
                    }
                }
            }
            
            return getValidString(hourTop, minuteTop);
        }
        
        hourTop = 24;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                temp = record[i] * 10 + record[j];
                if(temp >= 0 && temp < hourTop)
                {
                    hourTop = temp;
                }
            }
        }
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                temp = record[i] * 10 + record[j];
                if(temp >= 0 && temp < minuteTop)
                {
                    minuteTop = temp;
                }
            }
        }
        
        return getValidString(hourTop, minuteTop);
    }
    
    string getValidString(int hour, int minute)
    {
        string res;
        char temp;
        if(hour < 10)
        {
            res.push_back('0');
            temp = hour + '0';
            res.push_back(temp);
        }
        else
        {
            temp = (hour/10) + '0';
            res.push_back(temp);
            temp = (hour%10) + '0';
            res.push_back(temp);
        }
        
        res.push_back(':');
        
        if(minute < 10)
        {
            res.push_back('0');
            temp = minute + '0';
            res.push_back(temp);
        }
        else
        {
            temp = (minute/10) + '0';
            res.push_back(temp);
            temp = (minute%10) + '0';
            res.push_back(temp);
        }
        
        return res;
    }
};