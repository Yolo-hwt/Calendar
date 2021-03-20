#pragma once
#include"head.h"
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date() { year = 1949, month = 10, day = 1; }//默认构造函数
	Date(int y,int m,int d) { year = y, month = m ,day = d; }
	~Date() {};
	Date(const Date& someday);
	void Setdate();//设置日期
	bool Leapyear(int year);//判断是否为闰年
	int Getyearday(int year);//获取平闰年天数
	int Getmonthday(int year, int month);//获取对应月份天数
	int GetAllday(int year, int month, int day);//默认参数1949.10.1到此日期的天数
	
	//日期计算
	Date operator+ (int d);//日期加
	Date operator- (int d);//日期减
	Date operator++ ();//自增 (前置）    
	Date operator-- ();//自减（前置）
	int operator- (const Date d);//计算两个日期相差的天数

	//输出<<重载函数
	friend ostream& operator<< (ostream& os, const Date d);

	//测试日期格式
	int Check_Date(int y, int m, int d);
	
};

class Time :public Date//时间类Time
{
protected:
	int hour, minute, second;
	Time() { hour = 0; minute = 0; second = 0; }
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	Time(const Time& sometime) :Date(sometime)
	{
		hour = sometime.hour; 
		minute = sometime.minute;
		second = sometime.second;
	}
};
