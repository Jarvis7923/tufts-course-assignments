#include <time.h>
#include <stdio.h>
#include "problem2.h"

const char* get_weekday(int i) {
    const char* month[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    return month[i];
}

const char* get_month(int i) {
    const char* month[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    return month[i];
}


void print_time(time_t time) {

    struct tm* st = gmtime(&time);

    printf("%s, %s %02d, %d %02d:%02d:%02d\n", get_weekday(st->tm_wday), get_month(st->tm_mon),st->tm_mday, st->tm_year+1900, st->tm_hour, st->tm_min, st->tm_sec);

}

