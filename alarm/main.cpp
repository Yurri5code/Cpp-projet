#include <iostream>
#include "alarm.h"


int main(){
    Date today ={0};
    std::cout <<"Welcom To Alarm Clock"<<std::endl;
    std::cout <<"Let's start By a configuration of your time and date\n";
    Date::configureDate(&today);
    std::cout <<"Your time and date are configured successfuly ..."<<std::endl;
    if(const int x = Date::menu(); x == 1) {
        Date::printDate(today);
        Date::printTime(today);
        std::cout<<"\n End of the program, GOOD BYE \n";
    }else if(x == 2) {
        Date alarm = {0};
        Date::setAlarm(&alarm,today);
        std::cout <<"the Date and Time of alarm"<<std::endl;
        Date::printDate(alarm);
        Date::printTime(alarm);
        Date::timeBeforeRinging(alarm,today);
        std::cout<<"\nEnd of the program, GOOD BYE \n";
    }else {
        std::cout<<"\nEnd of the program, GOOD BYE \n";
    }
    return 0;
}
