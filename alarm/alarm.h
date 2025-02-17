//
// Created by claude delcroix on 16/02/2025.
//

#ifndef ALARM_H
#define ALARM_H
typedef struct Time Time;
struct Time {
    int hour;
    int minute;
    int seconde;
};

typedef struct Date date;
struct Date {
    int day;
    int month;
    int year;
    Time time;

    static int menu();
    static void configureDate(Date* today);
    static void printDate(const Date& today);
    static void printTime(const Date& today);
    static void setDate(Date* day);
    static void setTime(Date* day);
    static void setAlarm(Date* alarm,const Date& today);
    static int daysFromReference(const Date& date);
    static void calculateDifference(const Date& start, const Date& end, int& years, int& months, int& days);
    static Time calculateTimeDifference(const Time& start, const Time& end);
    static void timeBeforeRinging(const Date& alarm,const Date& today);
};



bool isLeapYear(int year);
int daysInMonth( int month, int year);


#endif //ALARM_H
