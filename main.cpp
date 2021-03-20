#include"head.h"
#include"Class.h"
int main()
{
	int choice = 1;
	cout << "开始之前先确定今天的日期：(年_月_日）" << endl;
	Date T;
	T.Setdate();
	cout << "准备好了吗？开始你的时间管理" << endl;
	cout << endl;
	while (choice)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "今天是：";
			cout << T;
			break;
		}
		case 2:
		{
			Date tomorrow;
			cout << "明天是：";
			tomorrow =++ T;
			cout << tomorrow;
			break;
		}
		case 3:
		{
			Date yesterday(--T);
			cout << "昨天是：";
			cout << yesterday;
			break;
		}
		case 4:
		{
			int contral;
			cout << "输入你想管理的未来时间天数：";
			cin >> contral;
			cout << "开始管理......" << endl;
			Date D(T+contral);
			cout << D;
			break;
		}
		case 5:
		{
			int contral;
			cout << "输入你想管理的过去时间天数：";
			cin >> contral;
			cout << "开始管理......" << endl;
			Date D(T-contral);
			cout << D;
			break;
		}
		case 6:
		{
			int y, m, d;
			int num;
			cout << "输入你希望的未来日期：(年_月_日)";
			cin >> y >> m >> d;
			Date holiday(y, m, d);
			if (!holiday.Check_Date(y, m, d))
			{
				cerr << "输入日期非法" << endl;
				break;
			}
			num = holiday - T;//日期相减
			cout << "距离目标日期还有：" << num << "天" << endl;
			break;
		}
		case 0:
		{
			cout << "时间管理结束，祝您生活愉快！" << endl;
			break;
		}
		default: {cerr << "Error choice!" << endl; break; }
		}
	}
	return 0;
}