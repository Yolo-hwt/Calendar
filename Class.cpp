#include "Class.h"
Date::Date(const Date& someday)//拷贝构造函数
{
	year = someday.year;
	month = someday.month;
	day = someday.day;
}
void Date:: Setdate() //设置日期
{
	int y, m, d;
	cout << "请输入设置的日期" << endl;
	cout << "年-月-日：";
	cin >> y >> m >> d;
	year = y, month = m, day = d;
	cout << "设置成功！现在是：" << year << "年" << month << "月" << day << "日" << endl;
}
bool Date::Leapyear(int year)//判断是否为闰年
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}
int Date:: Getyearday(int year)//获取平闰年天数
{
	int num;
	if (Leapyear(year))
		num = 366;
	else
		num = 365;
	return num;
}
int Date::Getmonthday(int year, int month)//获取对应月份天数
{
	int M[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Leapyear(year))
		M[2] = 29;
	else
		M[2] = 28;
	return M[month];
}
int Date::GetAllday(int year, int month, int day)//默认参数1949.10.1到此日期的天数
{
	int Days = 0;
	int y1, m1, d1;
	y1 = 1949, m1 = 10, d1 = 1;
	Days += (Getmonthday(y1, m1) - d1);
	m1++;
	for (m1; m1 <= 12; m1++)
	{
		Days += Getmonthday(y1, m1);
	}
	y1++;
	for (y1; y1 <= year; y1++)
	{
		Days += Getyearday(y1);
	}
	y1 = year, m1 = month, d1 = day;
	int i;
	for (i = 1; i < m1; i++)
	{
		Days += Getmonthday(y1, i);
	}
	Days += d1;
	return Days;
}
Date Date::operator+ (int d)   //+运算符重载函数
{
	Date temp(*this);//调用拷贝构造函数对temp临时对象初始化
	if (d < 0)//日期为负数时
	{
		d = -d;//此时为正数，调用-重载
		temp = (temp - d);
		return temp;
	}
	if (day == 0)
	{
		return temp;
	}

	temp.day += d;//重置当前天数
	int Monthday = Getmonthday(temp.year, temp.month);//获取对应年份下的月份天数
	if (temp.day <= Monthday&&temp.day>0)
		return temp;

	int flag = 1;
	while (flag)
	{
		if (temp.month == 12)
		{
			temp.year += 1;
			temp.month = 1;
			temp.day -= Monthday;
		}
		else//月份在1-11情况
		{
			temp.month += 1;
			temp.day -= Monthday;
		}

		Monthday = Getmonthday(temp.year, temp.month);
		if (temp.day == 0)
			temp.day = 1;
		if (temp.day <=Monthday&&temp.day>0)
			flag = 0;
	}
	return temp;
}
Date Date:: operator- (int d)
{	
	Date temp(*this);
	if (d < 0)
	{
		d = -d;//此时为正数，调用+重载
		temp = (temp + d);
		return temp;
	}
	if (d == 0)
	{
		return temp;
	}

	temp.day -= d; //重置当前天数
	int Monthday = Getmonthday(temp.year, temp.month);//获取对应年份下的月份天数
	if(temp.day <= Monthday&&temp.day>0)//天数仍在当前月份
		return temp;

	int flag = 1;
	while (flag)
	{
		if (temp.month == 1)
		{
			temp.year -= 1;
			temp.month = 12;
			temp.day += Monthday;

		}
		else//月份在2-12情况
		{
			temp.month -= 1;
			temp.day += Monthday;
		}
		Monthday = Getmonthday(temp.year, temp.month);
		if (temp.day == 0)
			temp.day = Monthday;
		if (temp.day <= Monthday&&temp.day>0)
			flag = 0;
	}

	return temp;
}
Date Date::operator++()
{
	Date temp;
	temp=*this+1;
	return temp;
}
Date Date::operator--()
{
	Date temp;
	temp = (*this) - 1;
	return temp;
}
int Date::operator- (const Date d)//计算两日期之间的天数差
{
	int day1, day2;
	day1 = GetAllday(this->year,this->month,this->day);
	day2 = GetAllday(d.year, d.month, d.day);
	return fabs(day1 - day2);
}
 ostream& operator<< (ostream& out, const Date d)
{
	 out << d.year << " 年 " << d.month << " 月 " << d.day << " 日 " << endl;
	 return out;
}
 int Date:: Check_Date(int y, int m, int d)//测试日期格式
 {
	 int flag=0;
	 if (y >= 1949 && m > 0 && m <= 12 && d > 0)
	 {
		 if (Getmonthday(y, m) >= d)
			 flag = 1;
	 }
	 else
		 flag = 0;
	 return flag;
 }