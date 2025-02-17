//
// Created by claude delcroix on 16/02/2025.
//
#include <iostream>
#include "alarm.h"
#include <ctime>

int Date::menu() {
    std::cout <<"1. Look at Time and Date"<<std::endl<<"2. Set alarm"<<std::endl<<"3.Exit \n";
    int x = 0;
    std::cout <<"your choice :";
    std::cin >> x;
    while(x < 1 or x > 3) {
        std::cout <<"wrong choice \n";
        std::cout <<"your choice :";
        std::cin >> x;
    }
    return x;
}

void Date::configureDate(Date* today) {
    std::cout <<"Put the information of the date  dd:mm:yy"<<std::endl;
    std::cout <<"day :";
    std::cin >> today->day;
    std::cout <<"month :";
    std::cin >> today->month;
    std::cout <<"year :";
    std::cin >> today->year;
    std::cout <<"Put the time information hh:mm:ss"<<std::endl;
    std::cout<<"hour :";
    std::cin >> today->time.hour;
    std::cout<<"minute :";
    std::cin>>today->time.minute;
    std::cout<<"seconde :";
    std::cin >> today->time.seconde;
    std::cout <<"the configuration is done....\n";
}

void Date::printDate(const Date& today) {
    std::cout << "Date : "<<today.day;
    if(today.month < 10) {
        std::cout<<": 0"<<today.month<<"/ "<<today.year<<std::endl;
    }else {
        std::cout<<"/ "<<today.month<<"/ "<<today.year<<std::endl;
    }
}

void Date::printTime(const Date& today) {
    std::cout <<"Time : "<<today.time.hour;
    if(today.time.minute < 10) {
        std::cout <<": 0"<<today.time.minute<<": "<<today.time.seconde;
    }else {
        std::cout <<": "<<today.time.minute<<": "<<today.time.seconde;
    }
}

void Date::setDate(Date* day) {
    std::cout <<"Day :";
    std::cin >>day->day;
    std::cout <<"Month :";
    std::cin>>day->month;
    std::cout<<"Year :";
    std::cin>>day->year;
}

void Date::setTime(Date* day) {
    std::cout <<"Hour :";
    std::cin>>day->time.hour;
    std::cout <<"Minute :";
    std::cin >>day->time.minute;
    std::cout <<"Seconde :";
    std::cin >> day->time.seconde;
}

void Date::setAlarm(Date* alarm,const Date& today) {
    std::cout <<"today's date "<<std::endl;
    printDate(today);
    printTime(today);

    std::cout <<"\nput the date for your alarm \n";
    setDate(alarm);
    setTime(alarm);
}

bool isLeapYear(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(const int month,const int year) {
    switch (month) {
        case 2: return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

int Date::daysFromReference(const Date& date) {
    int days = 0;
    for (int y = 0; y < date.year; ++y) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < date.month; ++m) {
        days += daysInMonth(m, date.year);
    }
    days += date.day;
    return days;
}

void Date::calculateDifference(const Date& start, const Date& end, int& years, int& months, int& days) {
    const int startDays = daysFromReference(start);
    const int endDays = daysFromReference(end);
    int difference = endDays - startDays;

    years = difference / 365;
    difference %= 365;
    months = difference / 30;
    days = difference % 30;
}

Time Date::calculateTimeDifference(const Time& start, const Time& end) {
    Time difference;

    // Convertir les deux temps en secondes
    const int startSeconds = start.hour * 3600 + start.minute * 60 + start.seconde;
    const int endSeconds = end.hour * 3600 + end.minute * 60 + end.seconde;

    // Calculer la différence en secondes
    int diffSeconds = std::abs(endSeconds - startSeconds);

    // Convertir la différence en heures, minutes et secondes
    difference.hour = diffSeconds / 3600;
    diffSeconds %= 3600;
    difference.minute = diffSeconds / 60;
    difference.seconde = diffSeconds % 60;

    return difference;
}

void Date::timeBeforeRinging(const Date& alarm,const Date& today) {
    int year(0),month(0),day(0);
    calculateDifference(today,alarm,year,month,day);
    std::cout<<"\n Your alarm will be in "<<std::endl;
    std::cout<<day <<"days , "<<month<<" months and "<<year<<" years "<<std::endl;
    const auto [hour, minute, seconde] = calculateTimeDifference(today.time,alarm.time);
    std::cout<<"\n Your alarm will in "<<hour<<"hour "<<minute<<" minute and "<<seconde<<std::endl;
}
