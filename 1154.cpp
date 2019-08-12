class Solution {
public:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int dayOfYear(string date) {
        int year = 0;
        for(int i = 0; i < 4; ++i)
            year = year * 10 + date[i] - '0';
        if(year % 400 == 0 || (year % 4 == 0 && year % 100))
            days[1] = 29;
        int month = 0, day = 0;
        for(int i = 5; i < 7; ++i)
            month = month * 10 + date[i] - '0';
        for(int i = 8; i < date.length(); ++i)
            day = day * 10 + date[i] - '0';
        int cnt = 0;
        for(int i = 0; i < month - 1; ++i)
            cnt += days[i];
        cnt += day;
        return cnt;
    }
};
