#pragma once
#include<string>
class Time {
	int hour;
	int minute;
	int second;

	void normalizeTime(int _hour, int _minute, int _second);

public:
	Time();
	Time(int _hour, int _minute, int _second);
	Time(const std::string& StrTime);
	Time(int AllInSeconds);

	void setHour(int _hour);
	void setMinute(int _minute);
	void setSecond(int _second);

	int getHour();
	int getMinute();
	int getSecond();

	int DiffBetwSeconds(Time& AnotherTime);
	Time addSeconds(int _second);
	Time subtractSeconds(int _second);
	int toSeconds();
	int toMinute();

	bool compare(Time& AnotherTime);
	std::string toStr();
};