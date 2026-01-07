#include "Time.h"
#include <iostream>
#include <cmath>
Time::Time() :hour(0), minute(0), second(0)
{
}

Time::Time(int _hour, int _minute, int _second) :hour(_hour), minute(_minute), second(_second)
{
    normalizeTime(hour, minute, second);
}

Time::Time(const std::string& StrTime)
{
    if (StrTime.length() == 8) {
        hour = stoi(StrTime.substr(0, 2));
        minute = stoi(StrTime.substr(3, 2));
        second = stoi(StrTime.substr(6, 2));
    }
    else {
        hour = 0;
        minute = 0;
        second = 0;
    }
    normalizeTime(hour, minute, second);
}

Time::Time(int AllInSeconds)
{
    hour = AllInSeconds / 3600;
    minute = (AllInSeconds % 3600) / 60;
    second = AllInSeconds % 60;
    normalizeTime(hour, minute, second);
}

void Time::setHour(int _hour)
{
    normalizeTime(_hour, minute, second);
}

void Time::setMinute(int _minute)
{
    normalizeTime(hour, _minute, second);
}

void Time::setSecond(int _second)
{
    normalizeTime(hour, minute, _second);
}

int Time::getHour()
{
    return hour;
}

int Time::getMinute()
{
    return minute;
}

int Time::getSecond()
{
    return second;
}

int Time::DiffBetwSeconds(Time& AnotherTime)
{
    int NowSeconds = toSeconds();
    int AnotherSeconds = AnotherTime.toSeconds();
    return abs(NowSeconds - AnotherSeconds);
}

Time Time::addSeconds(int _second)
{
    int totalSeconds = toSeconds() + _second;
    return Time(totalSeconds);
}

Time Time::subtractSeconds(int _second)
{
    int totalSeconds = toSeconds() - _second;
    return Time(totalSeconds);
}

int Time::toSeconds()
{
    return hour * 3600 + minute * 60 + second;
}

int Time::toMinute()
{
    double totalMinutes = hour * 60 + minute + second / 60.0;
    return static_cast<int>(round(totalMinutes));
}

bool Time::compare(Time& AnotherTime)
{
    return (toSeconds() >= AnotherTime.toSeconds());

}

std::string Time::toStr()
{
    return std::to_string(hour) + ":" + std::to_string(minute) + ':' + std::to_string(second);
}


void Time::normalizeTime(int _hour, int _minute, int _second) {

    if (_hour < 0) {
        _hour = abs(_hour);
    }
    if (_minute < 0) {
        _minute = abs(_minute);
    }
    if (_second < 0) {
        _second = abs(_second);
    }

    int totalSeconds = _hour * 3600 + _minute * 60 + _second;

    hour = (totalSeconds / 3600) % 24;
    minute = (totalSeconds % 3600) / 60;
    second = totalSeconds % 60;
}


