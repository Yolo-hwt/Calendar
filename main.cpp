#include"head.h"
#include"Class.h"
int main()
{
	int choice = 1;
	cout << "��ʼ֮ǰ��ȷ����������ڣ�(��_��_�գ�" << endl;
	Date T;
	T.Setdate();
	cout << "׼�������𣿿�ʼ���ʱ�����" << endl;
	cout << endl;
	while (choice)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "�����ǣ�";
			cout << T;
			break;
		}
		case 2:
		{
			Date tomorrow;
			cout << "�����ǣ�";
			tomorrow =++ T;
			cout << tomorrow;
			break;
		}
		case 3:
		{
			Date yesterday(--T);
			cout << "�����ǣ�";
			cout << yesterday;
			break;
		}
		case 4:
		{
			int contral;
			cout << "������������δ��ʱ��������";
			cin >> contral;
			cout << "��ʼ����......" << endl;
			Date D(T+contral);
			cout << D;
			break;
		}
		case 5:
		{
			int contral;
			cout << "�����������Ĺ�ȥʱ��������";
			cin >> contral;
			cout << "��ʼ����......" << endl;
			Date D(T-contral);
			cout << D;
			break;
		}
		case 6:
		{
			int y, m, d;
			int num;
			cout << "������ϣ����δ�����ڣ�(��_��_��)";
			cin >> y >> m >> d;
			Date holiday(y, m, d);
			if (!holiday.Check_Date(y, m, d))
			{
				cerr << "�������ڷǷ�" << endl;
				break;
			}
			num = holiday - T;//�������
			cout << "����Ŀ�����ڻ��У�" << num << "��" << endl;
			break;
		}
		case 0:
		{
			cout << "ʱ����������ף��������죡" << endl;
			break;
		}
		default: {cerr << "Error choice!" << endl; break; }
		}
	}
	return 0;
}