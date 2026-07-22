class Solution {
private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysFrom1971(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        int totalDays = 0;

        for (int i = 1971; i < year; ++i) {
            totalDays += isLeapYear(i) ? 366 : 365;
        }

        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
            if (i == 1 && isLeapYear(year)) {
                totalDays += 1;
            }
        }

        totalDays += day;
        return totalDays;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFrom1971(date1) - daysFrom1971(date2));
    }
};