#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PERIOD 126230400

int main(void)
{
    int counter, temp, month,day,hour,minute,second;
    int leap_year = 0;
    time_t seconds; 
    srand(time(0));
    time(&seconds);
    seconds = 1569684902;
    counter = seconds/PERIOD;
    counter = counter*4 + 1970;
    temp = seconds%PERIOD;
    if (temp>94694400)
    {
        temp = temp - 94694400;
        counter = counter + 3;
    }
    else if ((63072000<temp) && (temp<94694400))
    {
        temp = temp - 63072000;
        leap_year = 1;
        counter = counter + 2;
    }
    else if ((31536000<temp) && (temp<63072000))
    {
        temp = temp - 31536000;
        counter = counter + 1;
    }
    day= temp/86400;
    temp= temp%86400;
    hour= temp/3600;
    temp = temp%3600;
    minute = temp/60;
    second = temp%60;
    if(day<=31)
    {
        month = 1;
    }
    if((day>31)&&(day<=(59+leap_year)))
    {
        day=day-31;
        month = 2;
    }
    if((day>(59+leap_year))&&(day<=(90+leap_year)))
    {
        day=day-(59+leap_year);
        month = 3;
    }
    if((day>(90+leap_year))&&(day<=(120+leap_year)))
    {
        day=day-(90+leap_year);
        month = 4;
    }
    if((day>(120+leap_year))&&(day<=(151+leap_year)))
    {
        day=day-(120+leap_year);
        month = 5;
    }
    if((day>(151+leap_year))&&(day<=(181+leap_year)))
    {
        day=day-(151+leap_year);
        month = 6;
    }
    if((day>(181+leap_year))&&(day<=(212+leap_year)))
    {
        day=day-(181+leap_year);
        month = 7;
    }
    if((day>(212+leap_year))&&(day<=(243+leap_year)))
    {
        day=day-(212+leap_year);
        month = 8;
    }
    if((day>(243+leap_year))&&(day<=(273+leap_year)))
    {
        day=day-(243+leap_year);
        month = 9;
    }
    if((day>(273+leap_year))&&(day<=(304+leap_year)))
    {
        day=day-(273+leap_year);
        month = 10;
    }
    if((day>(304+leap_year))&&(day<=(334+leap_year)))
    {
        day=day-(304+leap_year);
        month = 11;
    }
    if((day>(334+leap_year))&&(day<=(365+leap_year)))
    {
        day=day-(334+leap_year);
        month = 12;
    }
    printf("Current day is: %d/%d/%d\n", day+1,month,counter);
    printf("Current time is: %02d:%02d:%02d GMT\n", hour,minute,second);
}