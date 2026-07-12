class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        long totalDays = 0;
        for (int i = 1971; i < year; ++i) {
            totalDays += 365;
            if (isLeap(i)) totalDays++;
        }
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
            if (i == 1 && isLeap(year)) totalDays++;
        }
        totalDays += day;
        return weeks[(totalDays + 4) % 7];
    }
private:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};