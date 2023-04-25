class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
         int daysInMonth[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
        string daysInWeek[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//remeber to start from sunday
        
        int sumOfDays = 0;
        
        for(int i = 1971 ; i < year ; i++){
            sumOfDays += 365;
            if((i%4 == 0 && i%100 != 0) || (i%400 == 0)) sumOfDays++; //if leap year simply increase days by 1
        }
        
        if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) daysInMonth[1] = 29;
        
        for(int i = 0 ; i < month-1 ; i++) sumOfDays += daysInMonth[i];//remember month - 1
        
        sumOfDays += day-1;
        ///yaha tk hum bas days hi count krre theyy
        
        return daysInWeek[(sumOfDays+5)%7];//+5 bcoz 1/1/1971 was friday
    }
};