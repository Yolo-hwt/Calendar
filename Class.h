#pragma once
#include"head.h"
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date() { year = 1949, month = 10, day = 1; }//Ĭ�Ϲ��캯��
	Date(int y,int m,int d) { year = y, month = m ,day = d; }
	~Date() {};
	Date(const Date& someday);
	void Setdate();//��������
	bool Leapyear(int year);//�ж��Ƿ�Ϊ����
	int Getyearday(int year);//��ȡƽ��������
	int Getmonthday(int year, int month);//��ȡ��Ӧ�·�����
	int GetAllday(int year, int month, int day);//Ĭ�ϲ���1949.10.1�������ڵ�����
	
	//���ڼ���
	Date operator+ (int d);//���ڼ�
	Date operator- (int d);//���ڼ�
	Date operator++ ();//���� (ǰ�ã�    
	Date operator-- ();//�Լ���ǰ�ã�
	int operator- (const Date d);//��������������������

	//���<<���غ���
	friend ostream& operator<< (ostream& os, const Date d);

	//�������ڸ�ʽ
	int Check_Date(int y, int m, int d);
	
};

class Time :public Date//ʱ����Time
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
