#include "Class.h"
Date::Date(const Date& someday)//�������캯��
{
	year = someday.year;
	month = someday.month;
	day = someday.day;
}
void Date:: Setdate() //��������
{
	int y, m, d;
	cout << "���������õ�����" << endl;
	cout << "��-��-�գ�";
	cin >> y >> m >> d;
	year = y, month = m, day = d;
	cout << "���óɹ��������ǣ�" << year << "��" << month << "��" << day << "��" << endl;
}
bool Date::Leapyear(int year)//�ж��Ƿ�Ϊ����
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}
int Date:: Getyearday(int year)//��ȡƽ��������
{
	int num;
	if (Leapyear(year))
		num = 366;
	else
		num = 365;
	return num;
}
int Date::Getmonthday(int year, int month)//��ȡ��Ӧ�·�����
{
	int M[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Leapyear(year))
		M[2] = 29;
	else
		M[2] = 28;
	return M[month];
}
int Date::GetAllday(int year, int month, int day)//Ĭ�ϲ���1949.10.1�������ڵ�����
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
Date Date::operator+ (int d)   //+��������غ���
{
	Date temp(*this);//���ÿ������캯����temp��ʱ�����ʼ��
	if (d < 0)//����Ϊ����ʱ
	{
		d = -d;//��ʱΪ����������-����
		temp = (temp - d);
		return temp;
	}
	if (day == 0)
	{
		return temp;
	}

	temp.day += d;//���õ�ǰ����
	int Monthday = Getmonthday(temp.year, temp.month);//��ȡ��Ӧ����µ��·�����
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
		else//�·���1-11���
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
		d = -d;//��ʱΪ����������+����
		temp = (temp + d);
		return temp;
	}
	if (d == 0)
	{
		return temp;
	}

	temp.day -= d; //���õ�ǰ����
	int Monthday = Getmonthday(temp.year, temp.month);//��ȡ��Ӧ����µ��·�����
	if(temp.day <= Monthday&&temp.day>0)//�������ڵ�ǰ�·�
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
		else//�·���2-12���
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
int Date::operator- (const Date d)//����������֮���������
{
	int day1, day2;
	day1 = GetAllday(this->year,this->month,this->day);
	day2 = GetAllday(d.year, d.month, d.day);
	return fabs(day1 - day2);
}
 ostream& operator<< (ostream& out, const Date d)
{
	 out << d.year << " �� " << d.month << " �� " << d.day << " �� " << endl;
	 return out;
}
 int Date:: Check_Date(int y, int m, int d)//�������ڸ�ʽ
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